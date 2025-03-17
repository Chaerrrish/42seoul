#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;
    const std::vector<int> cv;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}
    std::cout << "[vector] ------------------------------------" << std::endl;
    try
    {
        std::cout << "find 0 : " << *(easyfind(v, 0)) << std::endl;
        std::cout << "find 2 : " << *(easyfind(v, 2)) << std::endl;
        std::cout << "find -5 : " << *(easyfind(v, -5)) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "[deque] ------------------------------------" << std::endl;
    try
    {
        std::cout << "find 0 : " << *(easyfind(d, 0)) << std::endl;
        std::cout << "find 2 : " << *(easyfind(d, 2)) << std::endl;
        std::cout << "find 10 : " << *(easyfind(d, 10)) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "[list] ------------------------------------" << std::endl;
    try
    {
        std::cout << "find 0 : " << *(easyfind(l, 0)) << std::endl;
        std::cout << "find 2 : " << *(easyfind(l, 2)) << std::endl;
        std::cout << "find 10 : " << *(easyfind(l, 10)) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}