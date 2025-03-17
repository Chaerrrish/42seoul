#include "Span.hpp"

Span::Span(): N(0)
{
    std::cout << "Span :: Default Constructor called" << std::endl;
}

Span::Span(unsigned int N): N(N)
{
    std::cout << "Span :: Constructor called" << std::endl;
}

Span::~Span()
{
    std::cout << "Span :: Destructor called" << std::endl;
}

Span::Span(const Span& Span)
{
    *this = Span;
    std::cout << "Span :: Copy Constructor called" << std::endl;
}

Span& Span::operator=(const Span& Span)
{
    if (this != &Span)
    {
        this->N = Span.N;
        this->v = Span.v;
    }
    std::cout << "Span :: Copy assignment operator called" << std::endl;    
    return *this;
}

void Span::addNumber(int val)
{
    if (v.size() == N)
        throw std::runtime_error("Over max size N");
    v.push_back(val);
}

int Span::randomNumber() 
{ 
    return (std::rand()%1000); 
}

void Span::fillNumber()
{
    std::vector<int> buf(N, 0);
    srand(time(NULL));
    std::generate(buf.begin(), buf.end(), randomNumber);
    v = buf;
}

unsigned int Span::shortestSpan()
{
    if (v.size() < 2)
        throw std::runtime_error("Size N less than 2");
    std::sort(v.begin(), v.end());
    unsigned int res = INF;
    for (std::vector<int>::iterator it=v.begin()+1; it!=v.end(); it++)
    {
        unsigned int temp = *it - *(it-1);
        if (temp < res)
            res = temp;
    }
    return res;
}

unsigned int Span::longestSpan()
{
    if (v.size() < 2)
        throw std::runtime_error("Size N less than 2");
    std::sort(v.begin(), v.end());
    return *(v.end()-1) - *v.begin();
}