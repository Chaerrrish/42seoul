#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat 
{
    private :
        const std::string name;
        int grade;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };


        public :
            Bureaucrat();
            Bureaucrat(std::string name, int grade);
            ~Bureaucrat();
            Bureaucrat(const Bureaucrat& Bureaucrat);
            Bureaucrat& operator=(const Bureaucrat& Bureaucrat);

            std::string getName() const ;
            int getGrade() const ;
            void checkGrade(int newGrade) const ;
            void increaseGrade();
            void decreaseGrade();

            void signForm(AForm& form) const;
            void executeForm(AForm const& form);
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif