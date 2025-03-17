#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{
    std::cout << getName() << " :: RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
    std::cout << getName() << " :: RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << getName() << " :: RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& robotomyRequestForm) : AForm(robotomyRequestForm.getName(), robotomyRequestForm.getSignedGrade(), robotomyRequestForm.getExecGrade())
{
    *this = robotomyRequestForm;
    std::cout << this->getName() << " :: RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& robotomyRequestForm)
{
     if (this != &robotomyRequestForm)
    {
        // name, signGrade, executeGrade are constant variables, so it cannot changed.
        std::cout << this->getName() << " :: RobotomyRequestForm Copy assignment operator called(Do Nothing)" << std::endl;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    checkExecute(executor);
    
    int tmp = (rand() % 2); 

	std::cout << "drrrrrrrrrrrr...!" << std::endl;

	if (tmp)
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getName() << " has been robotomized fail..." << std::endl;
}