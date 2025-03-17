#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < ac; i++)
        {
            size_t len = std::strlen(av[i]);
            for (int j = 0; j < len; j++)
            {
                std::cout << static_cast<char>(toupper(av[i][j]));
            }
        }
        std::cout << std::endl;
    }
}