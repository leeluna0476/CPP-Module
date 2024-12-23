#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <cstdlib>
# include <deque>

template <typename T, typename Container>
class   MutantStack
{
    private:
        Container _storage;

    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        bool    empty() const;
        std::size_t  size() const;
        T       &top();
        const T &top() const;

        void    push(const T &value);
        void    pop();

        class   Iterator
        {
        };
};

template <typename T, typename Container>
bool    operator==(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y);

template <typename T, typename Container>
bool    operator<(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y);

template <typename T, typename Container>
bool    operator!=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y);

template <typename T, typename Container>
bool    operator>(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y);

template <typename T, typename Container>
bool    operator>=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y);

template <typename T, typename Container>
bool    operator<=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y);

# include "MutantStack.tpp"

#endif
