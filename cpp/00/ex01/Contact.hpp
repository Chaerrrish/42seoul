#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <iomanip>
# include <cctype>

class	Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		int	    add();
		int		checkIndex();
		void	printInfo();
		void	printAllInfo();
};

#endif