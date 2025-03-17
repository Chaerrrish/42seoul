#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    brain = new Brain();
    std::cout << "Dog Default Constructor called." << std::endl;
}

Dog::Dog(Brain* idea) : Animal("Dog")
{
    brain = new Brain(*idea);
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
    brain = new Brain(*(dog.brain));
    std::cout << "Dog Copy Constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    if (this != &dog)
    {
        this->type = dog.type;
        delete brain;
        brain = new Brain(*(dog.brain));
    }
    std::cout << "Dog Copy assignment operator called." << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bark Bark!" << std::endl;
}

void Dog::printBrain() const
{
    brain->printIdeas();
}