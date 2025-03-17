#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(-1)
{ }

void PhoneBook::add()
{
    if (index < 7)
        index++;
    else
        index = 0;
    if (!contacts[index].add())
        index--;
}

void PhoneBook::search()
{
    if (index == -1)
    {
        std::cout << "PhoneBook is empty!" << std::endl;
        return ;
    }
    std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "firstname" << "|";
	std::cout << std::setw(10) << "lastname" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;

	for (int i=0; i<8; i++)
	{
		std::cout << std::setw(10);
		std::cout<<i;
		std::cout<<"|";
		contacts[i].printInfo();
	}
	
	std::string str;
    int searchIndex = -1;

    while (true) {
        std::cout << "index : ";
        std::getline(std::cin, str);
        
        if (str.length() != 1 || str[0] < '0' || str[0] > '7') {
            std::cout << "Error: Invalid input. Please enter a number between 0 and 7." << std::endl;
            continue;
        }
        
        searchIndex = str[0] - '0';
        
        if (searchIndex > 7 || searchIndex < 0)
            std::cout << "Error : out of range" << std::endl;
        else if (contacts[searchIndex].checkIndex())
            std::cout << "Error : Empty index of Phonebook" << std::endl;
        else
            break;
    }
    contacts[searchIndex].printAllInfo();
}