#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
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

        class ExecuteNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        

    public:
        AForm();
        AForm(std::string name, int signedGrade, int execGrade);
        ~AForm();
        AForm(const AForm& form);
        AForm& operator=(const AForm& form);

        std::string getName() const;
        bool getSign() const;
        int getSignedGrade() const;
        int getExecGrade() const;
        void checkGrade(int newGrade) const;

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
        void checkExecute(Bureaucrat const& Bureaucrat) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif