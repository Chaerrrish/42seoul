#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal : Constructor called." << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << this->type << " : Constructor called."<< std::endl;
}

Animal::Animal(const Animal &animal)
{
    *this = animal;
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    if (this != &animal)
        this->type = animal.type;

    std::cout << "Animal Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const 
{
    std::cout << "I'm Animal" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}