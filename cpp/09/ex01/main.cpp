#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Input Error!" << std::endl;
        return (1);
    }
    RPN rpn;
    int result = rpn.calculate(av[1]);
    if (result == -1)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    else
        std::cout << result << std::endl;
    return (0);

}