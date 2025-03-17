#include "Intern.hpp"

Intern::Intern() 
{
    std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(Intern& Intern) 
{
    *this = Intern;
    std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern& Intern::operator=(Intern& Intern)
{
     if (this != &Intern)
    {
        // name, signGrade, executeGrade are constant variables, so it cannot changed.
        std::cout << "Intern Copy assignment operator called (Do Nothing)" << std::endl;
    }
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    AForm *form = NULL;
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int find = -1;

    for (int i=0; i<3; i++){
        if (name == names[i]){
            find = i;
            std::cout << "Intern can create Form : " << names[i] << std::endl;
            break;
        }
    }

    try{
        switch(find)
        {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
			throw DoesNotExistException();
        }
    }
    catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

    return form;
}

const char* Intern::DoesNotExistException::what() const throw()
{
    return "Intern cannot make form\n";
}