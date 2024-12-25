#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <cstdlib>
# include <stack>
# include <deque>

template <typename T>
class   MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        typedef typename std::stack<T, std::deque<T> >::container_type::iterator  iterator;

        iterator    begin();
        iterator    end();
};

# include "MutantStack.tpp"

#endif
