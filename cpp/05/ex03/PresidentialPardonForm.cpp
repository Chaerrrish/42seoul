#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{
    std::cout << getName() << " :: PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
    std::cout << getName() << " :: PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << getName() << " :: PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& PresidentialPardonForm) : AForm(PresidentialPardonForm.getName(), PresidentialPardonForm.getSignedGrade(), PresidentialPardonForm.getExecGrade())
{
    *this = PresidentialPardonForm;
    std::cout << this->getName() << " :: PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& PresidentialPardonForm)
{
     if (this != &PresidentialPardonForm)
    {
        // name, signGrade, executeGrade are constant variables, so it cannot changed.
        std::cout << this->getName() << " :: PresidentialPardonForm Copy assignment operator called (Do Nothing)" << std::endl;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    checkExecute(executor);
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}