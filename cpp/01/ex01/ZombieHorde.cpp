#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *newZombies = new Zombie[N];

    for (int i = 0; i < N; i++)
        newZombies[i].set_name(name);
    return (newZombies);
}