#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "[1] ------------------------------------------" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl; //17 출력

        mstack.pop(); //17 빼내기

        std::cout << mstack.size() << std::endl; // 1 출력

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl; //5, 3, 5, 737, 0 출력
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "[2] ------------------------------------------" << std::endl;
    {
        std::list<int> mylist;

        mylist.push_back(5);
        mylist.push_back(17);

        std::cout << mylist.back() << std::endl; //17 출력

        mylist.pop_back(); //17 out

        std::cout << mylist.size() << std::endl; // 1 출력

        mylist.push_back(3);
        mylist.push_back(5);
        mylist.push_back(737);
        //[...] 
        mylist.push_back(0);

        std::list<int>::iterator it = mylist.begin();
        std::list<int>::iterator ite = mylist.end();
        while (it != ite)
        {
            std::cout << *it << std::endl; // 5, 3, 5, 737, 0 출력
            ++it;
        }
        std::list<int> s(mylist);
    }
    std::cout << "[3] ------------------------------------------" << std::endl;
    {
        MutantStack<int> mstack;

        for (int i=1; i<=5; i++)
            mstack.push(i);

        {
            std::cout << "----- [begin end test]" << std::endl;
            MutantStack<int>::iterator it = mstack.begin();
            MutantStack<int>::iterator ite = mstack.end();
            while (it != ite)
            {
                std::cout << *it << std::endl;
                ++it;
            }
        }
        {
            std::cout << "----- [rbegin rend test]" << std::endl;
            MutantStack<int>::reverse_iterator rit = mstack.rbegin();
            MutantStack<int>::reverse_iterator rite = mstack.rend();
            while (rit != rite)
            {
                std::cout << *rit << std::endl;
                ++rit;
            }
        }
        {
            std::cout << "----- [cbegin cend test]" << std::endl;
            MutantStack<int>::const_iterator it = mstack.begin();
            MutantStack<int>::const_iterator ite = mstack.end();
            while (it != ite)
            {
                std::cout << *it << std::endl;
                ++it;
            }
        }
        {
            std::cout << "----- [crbegin crend test]" << std::endl;
            MutantStack<int>::const_reverse_iterator rit = mstack.rbegin();
            MutantStack<int>::const_reverse_iterator rite = mstack.rend();
            while (rit != rite)
            {
                std::cout << *rit << std::endl;
                ++rit;
                // *rit = 100;
            }
        }
    }
    return 0;
}