#include "Span.hpp"

int main()
{
    std::cout<< "[1] ------------------------------------" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(-2147483648);
        sp.addNumber(2147483647);
        sp.addNumber(-17);
        sp.addNumber(-9);
        sp.addNumber(-11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout<< "[2] ------------------------------------" << std::endl;
    {
        try
        {
            Span sp = Span(2);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17); // exception 발생
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception : " << e.what() << std::endl;
        }
    }
    std::cout<< "[3] ------------------------------------" << std::endl;
    {
        try
        {
            Span sp = Span(5);
            sp.addNumber(6);
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception : " << e.what() << std::endl;
        }
    }
    std::cout<< "[4] ------------------------------------" << std::endl;
    {
        try
        {
            Span sp = Span(10000);
            sp.fillNumber();
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception : " << e.what() << std::endl;
        }
    }

    return 0;
}