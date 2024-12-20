#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

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
        int     shortestSpan() const;
        int     longestSpan() const;
};

#endif
