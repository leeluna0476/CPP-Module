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

        bool    isGreaterDateThanDatabase(const std::string &date_input, const std::string &date_database, std::string::size_type pos = 0, std::string::size_type count = 4) const;

        bool    isValidDate(const std::string &line) const;
        float   isValidValue(const std::string &line, const std::string::size_type pos_start) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void                            isValidHeader(const std::string &line) const throw(Error);
        std::pair<std::string, float>   isValidData(const std::string &line) const throw(Error);

        void    addDataToList(const std::pair<std::string, float> &data);

        void    checkDatabase();
};

#endif
