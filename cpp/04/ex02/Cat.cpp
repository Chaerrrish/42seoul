#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    std::cout << "Cat Default Constructor called." << std::endl;
}

Cat::Cat(Brain* idea) : Animal("Cat")
{
    brain = new Brain(*idea);
    std::cout <<"Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    // this->type = cat.type;
    brain = new Brain(*(cat.brain));
    std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat)
    {
        this->type = cat.type;
        delete brain;
        brain = new Brain(*(cat.brain)); //깊은 복사
    }
    std::cout << "Cat Copy assignment operator called." << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow~" << std::endl;
}

void Cat::printBrain() const
{
    brain->printIdeas();
}