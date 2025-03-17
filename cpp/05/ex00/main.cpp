#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "--------------------------------------------" << std::endl;
        Bureaucrat a("a",1);
        Bureaucrat b("b",0);
        Bureaucrat c("c",100);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    try
    {
        std::cout << "--------------------------------------------" << std::endl;
        Bureaucrat t("test",3);
        std::cout<< t <<std::endl;
        t.increaseGrade();
        std::cout<< t <<std::endl;
        t.increaseGrade();
        std::cout<< t <<std::endl;
        t.increaseGrade();
        std::cout<< t <<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    try
    {
        std::cout << "--------------------------------------------" << std::endl;
        Bureaucrat t("test2",149);
        std::cout<< t <<std::endl;
        t.decreaseGrade();
        std::cout<< t <<std::endl;
        t.decreaseGrade();
        std::cout<< t <<std::endl; 
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }

    return 0;
}