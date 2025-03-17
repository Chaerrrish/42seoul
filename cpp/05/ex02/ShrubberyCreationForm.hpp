#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm& shrubberyCreationForm);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& shrubberyCreationForm);

		void execute(Bureaucrat const& executor) const;
};

#endif