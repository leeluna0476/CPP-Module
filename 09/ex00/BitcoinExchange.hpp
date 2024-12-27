#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include "Error.hpp"

class   BitcoinExchange
{
    private:
        bool    isValidDate(const std::string &line, const std::string::size_type pos_end);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void    isValidHeader(const std::string &line) throw(Error);
        void    isValidData(const std::string &line) throw(Error);
};

#endif
