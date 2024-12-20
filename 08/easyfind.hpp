#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

template <typename T>
int easyfind(const T &container, int integer_to_search)
{
    typename T::const_iterator ite = container.end();
    typename T::const_iterator it = std::find(container.begin(), ite, integer_to_search);

    if (it == ite)
    {
        throw std::exception();
    }

    return *it;
}

#endif
