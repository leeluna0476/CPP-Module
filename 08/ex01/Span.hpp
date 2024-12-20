#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <type_traits>

class   Span
{
    private:
        std::vector<int>    _storage;
        const unsigned int  _capacity;

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

            if (!std::is_same<value_type, int>::value)
            {
                throw std::logic_error("Can only add <int> data");
            }

            while (it != ite)
            {
                addNumber(*it);
                ++it;
            }
        }

        int     shortestSpan() const;
        int     longestSpan() const;

        void    printElements() const;
};

#endif
