#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm& presidentialPardonForm);
		PresidentialPardonForm& operator=(PresidentialPardonForm& presidentialPardonForm);

		void execute(Bureaucrat const& executor) const;
};

#endif