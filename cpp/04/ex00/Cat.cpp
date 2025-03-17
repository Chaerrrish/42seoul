#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat Default Constructor called." << std::endl;
}

Cat::Cat(const Cat &Cat)
{
    *this = Cat;
    std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat)
        this->type = cat.type;
    std::cout << "Cat Copy assignment operator called." << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow~" << std::endl;
}