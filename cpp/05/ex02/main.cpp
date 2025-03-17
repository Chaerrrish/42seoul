#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        std::cout << "[ 1 ]--------------------------------------------" << std::endl;
        Bureaucrat person1("person1", 30);
        ShrubberyCreationForm form1("form1");

        std::cout << "[ print ] " << person1 << std::endl;
        std::cout << "[ print ] " << form1 << std::endl;
        person1.signForm(form1);
        std::cout << "[ print ] " << form1 << std::endl;
        person1.executeForm(form1);
    }
    {
        std::cout <<std::endl << "[ 2 ]--------------------------------------------" << std::endl;
        Bureaucrat person2("person2", 30);
        RobotomyRequestForm form2("form2");

        std::cout << "[ print ] " << person2 << std::endl;
        std::cout << "[ print ] " << form2 << std::endl;
        person2.signForm(form2);
        std::cout << "[ print ] " << form2 << std::endl;
        person2.executeForm(form2);
    }
    {
        std::cout <<std::endl << "[ 3 ]--------------------------------------------" << std::endl;
        Bureaucrat person3("person3", 30);
        PresidentialPardonForm form3("form3");

        std::cout << "[ print ] " << person3 << std::endl;
        std::cout << "[ print ] " << form3 << std::endl;
        person3.signForm(form3);
        std::cout << "[ print ] " << form3 << std::endl;
        person3.executeForm(form3);
    }
    {
        std::cout <<std::endl << "[ 4 ]--------------------------------------------" << std::endl;
        Bureaucrat person4("person4", 15);
        PresidentialPardonForm form4("form4");

        std::cout << "[ print ] " << person4 << std::endl;
        std::cout << "[ print ] " << form4 << std::endl;
        person4.signForm(form4);
        std::cout << "[ print ] " << form4 << std::endl;
        person4.executeForm(form4);
    }
    {
        std::cout <<std::endl << "[ 5 ]--------------------------------------------" << std::endl;
        Bureaucrat person5("person5", 2);
        PresidentialPardonForm form5("form5");

        std::cout << "[ print ] " << person5 << std::endl;
        std::cout << "[ print ] " << form5 << std::endl;
        person5.signForm(form5);
        std::cout << "[ print ] " << form5 << std::endl;
        person5.executeForm(form5);
    }

    return 0;
}