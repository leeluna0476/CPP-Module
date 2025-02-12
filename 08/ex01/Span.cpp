#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : _capacity(0)
{
}

Span::Span(const Span &other) : _capacity(other._capacity)
{
    *this = other;
}

Span::Span(unsigned int n) : _capacity(n)
{
}

Span    &Span::operator=(const Span &other)
{
    if (&other == this || _capacity < other._storage.size())
    {
        return *this;
    }

    _storage = other._storage;

    return *this;
}

Span::~Span()
{
}

// add numbers and keep them sorted
void    Span::addNumber(int num)
{
    if (!_capacity || _storage.size() == _capacity)
    {
        throw std::out_of_range("Cannot add element");
    }
     
    std::vector<int>::iterator  it = std::upper_bound(_storage.begin(), _storage.end(), num);
    _storage.insert(it, num);
}

unsigned int Span::shortestSpan() const
{
    if (_storage.size() <= 1)
    {
        throw std::logic_error("Not enough elements to calculate span");
    }

    std::vector<int>::const_iterator  it = _storage.begin();
    std::vector<int>::const_iterator  ite = _storage.end();

    unsigned int span = *(it + 1) - *it;
    ++it;

    while (it + 1 != ite)
    {
        unsigned int diff = *(it + 1) - *it;
        if (diff < span)
        {
            span = diff;
        }

        ++it;
    }

    return span;
}

unsigned int Span::longestSpan() const
{
    if (_storage.size() <= 1)
    {
        throw std::logic_error("Not enough elements to calculate span");
    }

    return _storage.back() - _storage.front();
}

void    Span::printElements() const
{
    std::vector<int>::const_iterator  it = _storage.begin();
    std::vector<int>::const_iterator  ite = _storage.end();

    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << std::endl;
}
