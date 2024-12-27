#include "BitcoinExchange.hpp"
#include <utility>

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

bool    BitcoinExchange::isValidDate(const std::string &line, const std::string::size_type pos_end)
{
    (void)line;
    (void)pos_end;
    return true;
}

void    BitcoinExchange::isValidHeader(const std::string &line) throw(Error)
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

void    BitcoinExchange::isValidData(const std::string &line) throw(Error)
{
    std::string::size_type  pos = line.find(' ', 0);
    // if no space, pos = pipe. else, pos = the first space
    if (pos == std::string::npos)
    {
        pos = line.find('|', 0);
        // no even pipe, error
        if (pos == std::string::npos)
        {
            throw Error("bad input => " + line);
        }
    }

    if (!isValidDate(line, pos))
    {
        throw Error("bad input: date => " + line.substr(0, pos));
    }

    pos = line.find_first_not_of(' ', pos + 1);
    if (pos == std::string::npos)
    {
        throw Error("bad input => " + line);
    }
}
