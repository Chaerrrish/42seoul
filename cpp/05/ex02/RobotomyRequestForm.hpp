#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm& robotomyRequestForm);
		RobotomyRequestForm& operator=(RobotomyRequestForm& robotomyRequestForm);

		void execute(Bureaucrat const& executor) const;
};

#endif