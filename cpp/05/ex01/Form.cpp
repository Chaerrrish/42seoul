#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), sign(false), signedGrade(10), execGrade(10)
{
    std::cout << name << " :: Constructor called" << std::endl;
}

Form::Form(std::string name, int signedGrade, int execGrade) : name(name), sign(false), signedGrade(signedGrade), execGrade(execGrade)
{
    checkGrade(signedGrade);
    checkGrade(execGrade);
    std::cout << name << " :: Constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << name << " :: Destructor called" << std::endl;
}

Form::Form(const Form& Form) : name(Form.getName()), sign(Form.getSign()), signedGrade(Form.getSignedGrade()), execGrade(Form.getExecGrade())
{
    checkGrade(Form.getSignedGrade());
    checkGrade(Form.getExecGrade());
    *this = Form;
    std::cout << this->name << " :: Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& Form)
{
    if (this != &Form)
    {
        // name, signGrade, executeGrade are constant variables, so it cannot changed.
        this->sign = Form.getSign();
        std::cout << this->name << " :: Copy assignment operator called" << std::endl;
    }
    return *this;
}

std::string  Form::getName() const 
{
    return name;
}

bool Form::getSign() const
{
    return sign;
}

int Form::getSignedGrade() const
{
    return signedGrade;
}

int Form::getExecGrade() const
{
    return execGrade;
}

void Form::checkGrade(int newGrade)  const 
{
    if (newGrade < 1) 
        throw Form::GradeTooHighException();
    else if (newGrade > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& Bureaucrat)
{
    if (signedGrade >= Bureaucrat.getGrade()){
        sign = true;
    }
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low\n";
}

std::ostream&	operator<<(std::ostream& out, const Form& Form)
{
    out << Form.getName() << ", Form sign status : " << std::boolalpha << Form.getSign() << ", signGrade " << Form.getSignedGrade() << ", executeGrade " << Form.getExecGrade();
	return out;
}