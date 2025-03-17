#include "iter.hpp"

int main( void ) {   
    {
        std::cout << "[ int ]--------------------------------------------" << std::endl;
        int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        ::iter(arr1, 10, testFunc<int>);
        std::cout << std::endl;
    }
    {
        std::cout << "[ char ]--------------------------------------------" << std::endl;
        char arr2[7] = {'a','b','c','d','e','f','g'};
        ::iter(arr2, 7, testFunc<char>);
        std::cout << std::endl;
    }
    {
        std::cout << "[ string ]--------------------------------------------" << std::endl;
        std::string arr3[7]={"hello","my","name","is","chaoh","ye","yo"};
        ::iter(arr3, 7, testFunc<std::string>);
        std::cout << std::endl;
    }
    return 0;
}