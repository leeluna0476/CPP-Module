#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <cstdlib>

class   Span
{
    private:
        template <typename T, typename U>
        struct is_same
        {
            static const bool value = false;
        };

        template <typename T>
        struct is_same<T, T>
        {
            static const bool value = true;
        };

        std::vector<int>    _storage;
        const std::size_t   _capacity;

    public:
        Span();
        Span(const Span &other);
        Span(unsigned int n);
        Span   &operator=(const Span &other);
        ~Span();

        void    addNumber(int num);

        template <typename T>
        void    addRange(T it, T ite)
        {
            typedef typename std::iterator_traits<T>::value_type    value_type;

            if (!is_same<value_type, int>::value)
            {
                throw std::logic_error("Can only add <int> data");
            }

            while (it != ite)
            {
                addNumber(*it);
                ++it;
            }
        }

        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;

        void    printElements() const;
};

#endif
