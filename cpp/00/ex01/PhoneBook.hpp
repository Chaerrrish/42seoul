#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;
	
	public:
		PhoneBook();
		void	add();
		void	search();
};

#endif