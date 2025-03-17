#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(Brain* idea);
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);
        virtual ~Dog();
        void makeSound() const;
        void printBrain() const;
};

#endif