#include "FragTrap.hpp"

FragTrap::FragTrap(){
    this->name = "Default";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << this->name << " : FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap() {
    *this = fragTrap;
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap){
    if (this != &fragTrap){
        this->name = fragTrap.getName();
        this->hitPoints = fragTrap.getHitPoints();
        this->energyPoints = fragTrap.getEnergyPoints();
        this->attackDamage = fragTrap.getAttackDamage();
    }
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap(){

    std::cout << this->name << " : FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    if (this->hitPoints == 0)
        std::cout << "FragTrap " << this->name << " has no power to high five" << std::endl;
    else
        std::cout << "FragTrap " << this->name << " is asking for a high five!" << std::endl;
}