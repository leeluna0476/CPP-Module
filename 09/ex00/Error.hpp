#ifndef ERROR_HPP
# define ERROR_HPP

# include <string>

class   Error
{
    private:
        std::string _err_msg;

    public:
        Error();
        Error(const Error &other);
        Error   &operator=(const Error &other);
        Error(const std::string &err_msg);
        ~Error();

        const char    *what() const;
};

#endif
