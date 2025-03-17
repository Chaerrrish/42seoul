#include "Zombie.hpp"

int	main( void )
{
    Zombie test("stack1");

    Zombie  *zombie1 = newZombie("heap1");
    Zombie  *zombie2 = newZombie("heap2");
    
    zombie1->announce();
    zombie2->announce();
    
    delete zombie1;
    delete zombie2;

    randomChump("stack2");

    return 0;
}