#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		class DoesNotExistException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	public :
		Intern();
		~Intern();
		Intern(Intern &intern);
		Intern& operator=(Intern& intern);

		AForm* makeForm(std::string name, std::string target);
};



#endif 