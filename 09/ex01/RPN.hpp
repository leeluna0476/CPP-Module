#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

# define ERR_MSG() { std::cerr << "Error" << std::endl; }

class   RPN
{
    private:
        std::stack<int> _storage;

        int isOperator(char c);

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void    calculate(const std::string &line);
};

#endif
