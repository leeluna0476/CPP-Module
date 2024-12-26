#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &container, int integer_to_search)
{
    typename T::const_iterator ite = container.end();
    typename T::const_iterator it = std::find(container.begin(), ite, integer_to_search);

    if (it == ite)
    {
        throw std::exception();
    }

    return it;
}

template <typename T>
typename T::iterator easyfind(T &container, int integer_to_search)
{
    typename T::iterator ite = container.end();
    typename T::iterator it = std::find(container.begin(), ite, integer_to_search);

    if (it == ite)
    {
        throw std::exception();
    }

    return it;
}

#endif
