#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal() = 0;
        Animal(const Animal& Animal);
        Animal& operator=(const Animal& Animal);

        virtual void    makeSound() const = 0;
        std::string     getType() const;
};

#endif