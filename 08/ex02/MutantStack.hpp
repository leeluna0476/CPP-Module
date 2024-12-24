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

        bool        empty() const;
        std::size_t size() const;
        T           &top();
        const T     &top() const;

        void    push(const T &value);
        void    pop();

        class   Iterator
        {
            private:
                typename Container::iterator _it;

                Iterator();

            public:
                Iterator(const Iterator &other);
                Iterator(typename Container::iterator it);
                Iterator    &operator=(const Iterator &other);
                ~Iterator();

                T       &operator*();
                const T &operator*() const;

                void    operator++();
                void    operator--();

                const Iterator  operator++(int);
                const Iterator  operator--(int);

                Iterator    &operator+=(int n);
                Iterator    &operator-=(int n);

                Iterator    operator+(int n) const;
                Iterator    operator-(int n) const;

                bool    operator==(const typename MutantStack<T, Container>::Iterator &other) const;
                bool    operator!=(const typename MutantStack<T, Container>::Iterator &other) const;
        };

        Iterator    begin();
        Iterator    end();
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
