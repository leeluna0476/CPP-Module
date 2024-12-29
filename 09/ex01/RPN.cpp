#include "RPN.hpp"
#include <iostream>
#include <utility>
#include <sstream>

RPN::RPN()
{
}

RPN::RPN(const RPN &other) : _storage(other._storage)
{
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _storage = other._storage;
    }

    return *this;
}

RPN::~RPN()
{
}

int    RPN::isOperator(char c)
{
    int i = 0;
    while ("+-*/"[i])
    {
        if ("+-*/"[i] == c)
        {
            return i;
        }
        ++i;
    }
    
    return -1;
}

static int  add(int a, int b)
{
    return a + b;
}

static int  sub(int a, int b)
{
    return a - b;
}

static int  mul(int a, int b)
{
    return a * b;
}

static int  _div(int a, int b)
{
    return a / b;
}

void    RPN::calculate(const std::string &line)
{
    int (*operators[4])(int, int) = { add, sub, mul, _div };

    std::string::size_type  pos = line.find_first_not_of(' ', 0);

    while (pos != std::string::npos)
    {
        std::string::size_type  end = line.find(' ', pos);

        int num_to_push;
        std::string token;
        token = end == std::string::npos ? line.substr(pos) : line.substr(pos, end - pos);

        int opidx = isOperator(token[0]);

        if (opidx != -1)
        {
            if (_storage.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }

            int num1 = _storage.top();
            _storage.pop();
            int num2 = _storage.top();
            _storage.pop();

            num_to_push = operators[opidx](num2, num1);
        }
        else
        {
            std::stringstream   ss(token);
            ss >> num_to_push;
        }

        _storage.push(num_to_push);
        pos = line.find_first_not_of(' ', pos + 1);
    }

    std::cout << _storage.top() << std::endl;
}
