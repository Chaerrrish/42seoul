#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), sign(false), signedGrade(10), execGrade(10)
{
    std::cout << name << " :: Constructor called" << std::endl;
}

AForm::AForm(std::string name, int signedGrade, int execGrade) : name(name), sign(false), signedGrade(signedGrade), execGrade(execGrade)
{
    checkGrade(signedGrade);
    checkGrade(execGrade);
    std::cout << name << " :: Constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << name << " :: Destructor called" << std::endl;
}

AForm::AForm(const AForm& AForm) : name(AForm.getName()), sign(AForm.getSign()), signedGrade(AForm.getSignedGrade()), execGrade(AForm.getExecGrade())
{
    checkGrade(AForm.getSignedGrade());
    checkGrade(AForm.getExecGrade());
    *this = AForm;
    std::cout << this->name << " :: Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& AForm)
{
    if (this != &AForm)
    {
        // name, signGrade, executeGrade are constant variables, so it cannot changed.
        this->sign = AForm.getSign();
        std::cout << this->name << " :: Copy assignment operator called" << std::endl;
    }
    return *this;
}

std::string  AForm::getName() const 
{
    return name;
}

bool AForm::getSign() const
{
    return sign;
}

int AForm::getSignedGrade() const
{
    return signedGrade;
}

int AForm::getExecGrade() const
{
    return execGrade;
}

void AForm::checkGrade(int newGrade)  const 
{
    if (newGrade < 1) 
        throw AForm::GradeTooHighException();
    else if (newGrade > 150)
        throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& Bureaucrat)
{
    if (signedGrade >= Bureaucrat.getGrade()){
        sign = true;
    }
    else
        throw GradeTooLowException();
}

void AForm::checkExecute(Bureaucrat const& Bureaucrat) const
{
    if (sign == false)
        throw ExecuteNotSignedException();
    if (Bureaucrat.getGrade() > execGrade)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low\n";
}

const char* AForm::ExecuteNotSignedException::what() const throw()
{
    return "Not Signed\n";
}

std::ostream&	operator<<(std::ostream& out, const AForm& AForm)
{
    out << AForm.getName() << ", Form sign status : " << std::boolalpha << AForm.getSign() << ", signGrade " << AForm.getSignedGrade() << ", executeGrade " << AForm.getExecGrade();
	return out;
}