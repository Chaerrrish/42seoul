#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void testDifferentTypes() {
    std::cout<<std::endl<<"==================================";
    std::cout << "\n[TEST] Array<double>\n";
    Array<double> doubleArray(3);
    doubleArray[0] = 3.14;
    doubleArray[1] = 2.71;
    doubleArray[2] = 1.618;
    for (int i = 0; i < doubleArray.size(); i++)
        std::cout << doubleArray[i] << " ";
    std::cout << std::endl;

    std::cout << "\n[TEST] Array<std::string>\n";
    Array<std::string> strArray(2);
    strArray[0] = "Hello";
    strArray[1] = "World";
    for (int i = 0; i < strArray.size(); i++)
        std::cout << strArray[i] << " ";
    std::cout<<std::endl;
    std::cout<<"==================================="<<std::endl<<std::endl;
}

void testEmptyArray() {
    std::cout<<std::endl<<"==================================";
    std::cout << "\n[TEST] Empty Array\n";
    Array<int> emptyArray;
    
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

    try {
        emptyArray[0] = 42;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout<<"==================================="<<std::endl<<std::endl;
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    //추가 테스트
    testEmptyArray();
    testDifferentTypes();
    return 0;
}
