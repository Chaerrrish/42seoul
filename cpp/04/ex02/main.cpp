#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main( void ) {
    Animal* meta[10];

    for(int i=0; i<10; i++)
    {
        if (i % 2 == 0) meta[i] = new Cat();
        else meta[i] = new Dog();
    }

    std::cout << "--------------------" << std::endl;

    for(int i=0; i<10; i++)
    {
        delete meta[i];
    }

    std::cout << "--------------------" << std::endl;

    std::string cat_arr[100];
    for(int i=0; i<100; i++) cat_arr[i] = "cat_brain";
    Brain*  cat_brain = new Brain(cat_arr);
    // brain->printIdeas();

    std::cout << "--------------------" << std::endl;

    Cat *cat = new Cat(cat_brain);
    cat->printBrain();

    std::cout << "--------------------" << std::endl;

    Cat a(cat_brain);
    Cat b = a;
    b.makeSound();
    b.printBrain();

    std::cout << "--------------------" << std::endl;

	delete cat_brain;
	delete cat;

    return 0;
}