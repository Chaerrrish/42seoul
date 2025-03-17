#include "Contact.hpp"

int isEmpty(std::string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return (1);
	}
	return (0);
}

int Contact::checkIndex()
{
	return (firstname == "");
}

int Contact::add()
{
    std::cout << "Input Firstname : ";
	std::getline(std::cin, firstname);
	if (firstname.empty() || std::cin.eof() || !isEmpty(firstname))
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return (0);
	}

	std::cout << "Input Lastname : " ;
	std::getline(std::cin, lastname);
	if (lastname.empty() || std::cin.eof() || !isEmpty(lastname))
	{
		std::cout << "Fields cannot be empty";
		return (0);
	}

	std::cout << "Input Nickname : " ;
	std::getline(std::cin, nickname);
	if (nickname.empty() || std::cin.eof() || !isEmpty(nickname))
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return (0);
	}

	std::cout << "Input Phone Number : " ;
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty() || std::cin.eof() || !isEmpty(phoneNumber))
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return (0);
	}

	std::cout << "Input secrete : " ;
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty() || std::cin.eof() || !isEmpty(darkestSecret))
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return (0);
	}
	return (1);
}

void	Contact::printInfo()
{
	std::cout << std::setw(10);
	if (firstname.length() > 10)
	{
		std::string	temp = firstname.substr(0, 9);
		temp += '.';
		std::cout<<temp;
	}
	else
		std::cout<<firstname;

	std::cout<<"|";

	std::cout << std::setw(10);
	if (lastname.length() > 10)
	{
		std::string	temp = lastname.substr(0, 9);
		temp += '.';
		std::cout<<temp;
	}
	else
		std::cout<<lastname;

	std::cout<<"|";

	std::cout << std::setw(10);
	if (nickname.length() > 10)
	{
		std::string	temp = nickname.substr(0, 9);
		temp += '.';
		std::cout<<temp;
	}
	else
		std::cout<<nickname;

	std::cout<<std::endl;
}

void	Contact::printAllInfo()
{
	std::cout<<"firstname : "<<firstname<<std::endl;
	std::cout<<"lastname : "<<lastname<<std::endl;
	std::cout<<"nickname : "<<nickname<<std::endl;
	std::cout<<"phonenumber : "<<phoneNumber<<std::endl;
	std::cout<<"darkest secret : "<<darkestSecret<<std::endl;
}