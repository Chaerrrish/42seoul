#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << type << " : Constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    this->type = type;
    std::cout << type << " : Constructor called (Animal)" << std::endl;
}

Animal::~Animal()
{
    std::cout << type << " : Destructor called (Animal)" << std::endl;
}

Animal::Animal(const Animal& Animal)
{
    *this = Animal;
    std::cout << this->type << " : Copy Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& Animal)
{
    if (this != &Animal)
    {
        this->type = Animal.type;
    }
    std::cout << this->type << " : Copy assignment operator called" << std::endl;
    return *this;
}

void    Animal::makeSound() const
{
    std::cout << this->type << " : Animal no sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}