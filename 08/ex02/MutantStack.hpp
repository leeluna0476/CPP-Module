#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <cstdlib>
# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class   MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        typedef typename std::stack<T, Container >::container_type::iterator            iterator;
        typedef typename std::stack<T, Container >::container_type::const_iterator      const_iterator;
        typedef typename std::stack<T, Container >::container_type::reverse_iterator    reverse_iterator;
        typedef typename std::stack<T, Container >::container_type::reverse_iterator    const_reverse_iterator;

        iterator        begin();
        iterator        end();
        const_iterator  begin() const;
        const_iterator  end() const;

        reverse_iterator        rbegin();
        reverse_iterator        rend();
        const_reverse_iterator  rbegin() const;
        const_reverse_iterator  rend() const;
};

# include "MutantStack.tpp"

#endif
