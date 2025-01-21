#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <exception>
#include <iostream>
#include <iomanip>
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &)
{
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

// 정상적인 date format으로 들어온다고 가정한다.
bool    BitcoinExchange::isGreaterDateThanDatabase(const std::string &date_input, const std::string &date_database, std::string::size_type pos, std::string::size_type count) const
{
    unsigned int    input;
    std::stringstream   ss(date_input.substr(pos, count));
    ss >> input;

    unsigned int    database;
    ss.clear();
    ss.str(date_database.substr(pos, count));
    ss >> database;

    if (input > database)
    {
        return true;
    }

    // day까지 확인 완료.
    if (pos == 8)
    {
        return false;
    }

    return isGreaterDateThanDatabase(date_input, date_database, pos + count + 1, 2);
}

bool    BitcoinExchange::isValidDate(const std::string &line) const
{
    // check year
    std::string::size_type  pos = line.find('-', 0);
    // - 기호가 존재하지 않거나, 음수를 입력했을 경우.
    if (pos == std::string::npos || !pos)
    {
        return false;
    }

    unsigned int    year;
    std::stringstream   ss(line.substr(0, pos));
    ss >> year;

    // check month
    ++pos;
    if (line[pos] == '0')
    {
        if (line[pos + 1] < '1' || line[pos + 1] > '9')
        {
            return false;
        }
    }
    else if (line[pos] == '1')
    {
        if (line[pos + 1] < '0' || line[pos + 1] > '2')
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    // check day
    unsigned int    month;
    ss.clear();
    ss.str(line.substr(pos, 2));
    ss >> month;

    unsigned int    day;
    ss.clear();
    ss.str(line.substr(pos + 3, 2));
    ss >> day;

    if (!day)
    {
        return false;
    }

    // 2월은 따로 체크.
    if (month == 2)
    {
        // 윤년
        if (day > (!(year % 400) || !(year % 4) ? 29 : 28))
        {
            return false;
        }
    }
    else
    {
        if (day > (month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31))
        {
            return false;
        }
    }

    return true;
}

double   BitcoinExchange::isValidValue(const std::string &line, const std::string::size_type pos_start) const
{
    double   value;
    std::stringstream   ss(line.substr(pos_start));
    ss >> value;
    if (value <= 0.0)
    {
        return 0.0;
    }
    else if (value >= 1000.0)
    {
        return -1.0;
    }

    return value;
}

void    BitcoinExchange::isValidHeader(const std::string &line) const throw(Error)
{
    std::string::size_type  pos = line.find("date", 0);
    if (pos)
    {
        throw Error("bad input => " + line);
    }

    pos = line.find_first_not_of(' ', 4);
    if (pos == std::string::npos || line[pos] != '|')
    {
        throw Error("bad input => " + line);
    }

    pos = line.find_first_not_of(' ', pos + 1);
    if (pos == std::string::npos || line.find("value", pos) != pos || (line[pos + 5] != '\n' && line[pos + 5]))
    {
        throw Error("bad input => " + line);
    }
}

std::pair<std::string, double>    BitcoinExchange::isValidData(const std::string &line) const throw(Error)
{
    std::pair<std::string, double> date_value;

    // find the first space or a pipe
    std::string::size_type  pos = line.find_first_not_of("0123456789-", 0);
    if (pos != 10 || (line[pos] != '|' && line[pos] != ' '))
    {
        throw Error("bad input => " + line);
    }

    if (!isValidDate(line))
    {
        throw Error("bad input - date => " + line.substr(0, pos));
    }

    date_value.first = line.substr(0, pos);

    // 공백만 있고 파이프가 없다면
    // line[pos] == '|'인 경우에는 문제 x.
    if (line[pos] == ' ')
    {
        pos = line.find_first_not_of(' ', pos);
        if (pos == std::string::npos || line[pos] != '|')
        {
            throw Error("bad input => " + line);
        }
    }

    // 현 시점에서 line[pos] == '|'
    // 파이프 이후에 나오는 공백 모두 건너뛴다.
    pos = line.find_first_not_of(' ', pos + 1);
    if (pos == std::string::npos)
    {
        throw Error("bad input => " + line);
    }

    // 더 이상 숫자 외의 문자가 나오면 안된다.
    if (line.find_first_not_of("0123456789.-", pos) != std::string::npos || std::count(line.begin() + pos, line.end(), '.') > 1 || std::count(line.begin() + pos, line.end(), '-') > 1)
    {
        throw Error("bad input => " + line);
    }

    // ( 0, 1000 ) check
    double   value = isValidValue(line, pos);
    if (!value)
    {
        throw Error("not a positive number => " + line.substr(pos));
    }
    else if (value == -1)
    {
        throw Error("too large number => " + line.substr(pos));
    }

    date_value.second = value;

    return date_value;
}

void    BitcoinExchange::addDataToList(const std::pair<std::string, double> &data)
{
    list.insert(data);
}

// infile == data.csv
void    BitcoinExchange::exchangeBitcoin(std::ifstream &infile)
{
    std::map<std::string, double>::iterator data = list.begin();

    infile.clear();
    infile.seekg(0, std::ios::beg);

    std::string line;
    std::string before;
    std::getline(infile, line);

    while (!std::getline(infile, line).eof())
    {
        if (!isGreaterDateThanDatabase(data->first, line))
        {
            break;
        }

        before = line;
    }

	// if data.csv is empty
	if (!line.size() && !before.size())
	{
		std::cerr << "Cannot get an exchange rate" << std::endl;
		return;
	}

    double   exchange_rate;
    std::string target;

    std::string::size_type  pos = before.find(',', 0);
    if (data->first != line.substr(0, pos))
    {
        target = before.substr(pos + 1);
    }
    else
    {
        target = line.substr(pos + 1);
    }

    std::stringstream   ss(target);
    ss >> exchange_rate;

    std::cout << data->first << " => " << data->second << " = " << data->second * exchange_rate << std::endl;

    list.erase(data);
}
