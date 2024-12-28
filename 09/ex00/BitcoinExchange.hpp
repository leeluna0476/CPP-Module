#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <list>
# include <utility>
# include "Error.hpp"

class   BitcoinExchange
{
    private:
        std::list<std::pair<std::string, float> >    list;

        bool    isValidDate(const std::string &line);
        float   isValidValue(const std::string &line, const std::string::size_type pos_start);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void    isValidHeader(const std::string &line) throw(Error);
        std::pair<std::string, float>    isValidData(const std::string &line) throw(Error);
};

#endif
