#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool sign;
        const int signedGrade;
        const int execGrade;
    
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

    public:
        Form();
        Form(std::string name, int signedGrade, int execGrade);
        ~Form();
        Form(const Form& form);
        Form& operator=(const Form& form);

        std::string getName() const;
        bool getSign() const;
        int getSignedGrade() const;
        int getExecGrade() const;
        void checkGrade(int newGrade) const;

        void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif