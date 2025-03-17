#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook phonebook;

	while (1)
	{
		std::cout<<"Enter [ADD, SEARCH or EXIT] : ";
		std::string str;
		std::getline(std::cin,str);

		if (std::cin.eof())
			break ;

		if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		else if (str == "EXIT")
			return 0;
		else
			std::cout<<"Invalid Command\n";
		std::cin.clear();
	}
	return 0;
}