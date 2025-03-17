#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    {
        std::cout << "[ 1 ]--------------------------------------------" << std::endl;
        Bureaucrat person1("person1", 30);
        Intern intern;
        AForm *form1 = intern.makeForm("shrubbery creation", "shrubbery");

        std::cout << "[ print ] " << *form1 << std::endl;
        person1.signForm(*form1);
        std::cout << "[ print ] " << *form1 << std::endl;
        person1.executeForm(*form1);
    }
    {
        std::cout <<std::endl << "[ 2 ]--------------------------------------------" << std::endl;
        Bureaucrat person2("person2", 30);
        Intern intern;
        AForm *form2 = intern.makeForm("robotomy request", "robotomy");

        std::cout << "[ print ] " << *form2 << std::endl;
        person2.signForm(*form2);
        std::cout << "[ print ] " << *form2 << std::endl;
        person2.executeForm(*form2);
    }
    {
        std::cout <<std::endl<< "[ 3 ]--------------------------------------------" << std::endl;
        Bureaucrat person3("person3", 2);
        Intern intern;
        AForm *form3 = intern.makeForm("presidential pardon", "presidential");

        std::cout << "[ print ] " << *form3 << std::endl;
        person3.signForm(*form3);
        std::cout << "[ print ] " << *form3 << std::endl;
        person3.executeForm(*form3);
    }
    {
        std::cout <<std::endl<< "[ 4 ]--------------------------------------------" << std::endl;
        Bureaucrat person4("person4", 2);
        Intern intern;
        AForm *form4 = intern.makeForm("error Form", "error");

        if (form4){ //skip
            std::cout << "[ print ] " << *form4 << std::endl;
            person4.signForm(*form4);
            std::cout << "[ print ] " << *form4 << std::endl;
            person4.executeForm(*form4);
        }
    
    }
    return 0;
}