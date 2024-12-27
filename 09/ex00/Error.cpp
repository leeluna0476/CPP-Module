#include "Error.hpp"

Error::Error()
{
}


Error::Error(const std::string &err_msg) : _err_msg(err_msg)
{
}

Error::Error(const Error &other) : _err_msg(other._err_msg)
{
}

Error   &Error::operator=(const Error &other)
{
    _err_msg = other._err_msg;
    return *this;
}

Error::~Error()
{
}

const char  *Error::what() const
{
    return _err_msg.c_str();
}
