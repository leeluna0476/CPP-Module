#include "BitcoinExchange.hpp"
#include <sstream>

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

    if (input < database)
    {
        return false;
    }

    // day까지 확인 완료.
    if (pos == 8)
    {
        return true;
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

float   BitcoinExchange::isValidValue(const std::string &line, const std::string::size_type pos_start) const
{
    float   value;
    std::stringstream   ss(line.substr(pos_start));
    ss >> value;
    if (value <= 0.0 || value >= 1000.0)
    {
        return 0.0;
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

std::pair<std::string, float>    BitcoinExchange::isValidData(const std::string &line) const throw(Error)
{
    std::pair<std::string, float> date_value;

    // find the first space or a pipe
    std::string::size_type  pos = line.find_first_of(" |", 0);
    if (pos == std::string::npos)
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

    // 더 이상 공백이 나오면 안된다.
    if (line.find(' ', pos) != std::string::npos)
    {
        throw Error("bad input => " + line);
    }

    // ( 0, 1000 ) check
    float   value = isValidValue(line, pos);
    if (!value)
    {
        throw Error("bad input - value => " + line.substr(pos));
    }

    date_value.second = value;

    return date_value;
}

void    BitcoinExchange::addDataToList(const std::pair<std::string, float> &data)
{
    list.push_back(data);
}
