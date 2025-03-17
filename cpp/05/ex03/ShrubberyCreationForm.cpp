#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137)
{
    std::cout << getName() << " :: ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
    std::cout << getName() << " :: ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << getName() << " :: ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& shrubberyCreationForm) : AForm(shrubberyCreationForm.getName(), shrubberyCreationForm.getSignedGrade(), shrubberyCreationForm.getExecGrade())
{
    *this = shrubberyCreationForm;
    std::cout << this->getName() << " :: ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& shrubberyCreationForm)
{
     if (this != &shrubberyCreationForm)
    {
        // name, signedGrade, execGrade are constant variables, so it cannot changed.
        std::cout << this->getName() << " :: ShrubberyCreationForm Copy assignment operator called (Do Nothing)" << std::endl;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    checkExecute(executor);

    std::ofstream out(getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	
	 std::string shrubbery =
    "        __ _.--..--._ _ \n\
        .-' _/   _/\\_   \\_'-. \n\
        |__ /   _/\\__/\\_   \\__| \n\
        |___/\\_\\__/  \\___| \n\
                \\__/ \n\
                \\__/ \n\
                \\__/ \n\
                    \\__/ \n\
                ____\\__/___ \n\
        . - '             ' -. \n\
        /                      \\ \n\
    ~~~~~~~  ~~~~~ ~~~~~  ~~~ ~~~  ~~~~~ \n";
    out << shrubbery;
    out.close();
}