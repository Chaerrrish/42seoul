#include "Brain.hpp"

Brain::Brain()
{
    for(int i = 0; i < 100; ++i)
        this->ideas[i] = 'A' + (i % 26);
    std::cout << "Brain : Constructor called" << std::endl;
}

Brain::Brain(std::string *idea)
{
    if (idea == nullptr)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] ="";
    }
    for (int i = 0; i < 100; ++i)
        ideas[i] = idea[i];
    std::cout << "Brain : Idea Constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = brain.ideas[i];
    std::cout << "Brain : Copy Constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
    if (this != &brain)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = brain.ideas[i];
    }
    std::cout << "Brain : Copy Assignment Operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain : Destructor called" << std::endl;
}

void Brain::printIdeas() const
{
    for (int i = 0; i < 100; ++i)
        std::cout << i << " : " << ideas[i] << " " << std::endl;;
    std::cout << std::endl; 
}