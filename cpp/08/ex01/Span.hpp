#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <vector>

# define INF 4294967295

class Span {
    private:
        std::vector<int> v;
        unsigned int N;
        Span();

    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span& Span);
        Span& operator=(const Span& Span);

        void addNumber(int val);
        void fillNumber();
        static int randomNumber();
        unsigned int shortestSpan();
        unsigned int longestSpan();
};


#endif