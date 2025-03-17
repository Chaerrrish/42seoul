#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150){
    std::cout << name << " :: Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    checkGrade(grade);
    std::cout << name << " :: Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << name << " :: Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    checkGrade(grade);
    *this = bureaucrat;
    std::cout << this->name << " :: Copy Constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this != &bureaucrat)
    {
        this->grade = bureaucrat.getGrade();
        std::cout << this->name << " :: Copy assignment operator called" << std::endl;
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::checkGrade(int newGrade)  const 
{
    if (newGrade < 1) 
        throw Bureaucrat::GradeTooHighException();
    else if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::increaseGrade()
{
    checkGrade(grade-1);
    grade--;
}

void Bureaucrat::decreaseGrade()
{
    checkGrade(grade+1);
    grade++;
}

void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout<< this->getName() << " signed " << form.getName() <<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout<< this->getName() << " couldn't sign " << form.getName() << " because " << e.what();
    }
}

void Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout<< this->getName() << " executed " << form.getName() <<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout<< this->getName() << " couldn't execute " << form.getName() << " because " << e.what();
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low\n";
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& Bureaucrat)
{
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return out;
}