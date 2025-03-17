#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << name << " : ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap()
{
	*this = scavTrap;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap){
    if (this != &scavTrap){
        this->name = scavTrap.getName();
        this->hitPoints = scavTrap.getHitPoints();
        this->energyPoints = scavTrap.getEnergyPoints();
        this->attackDamage = scavTrap.getAttackDamage();
    }
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout <<name << " : ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0){
        std::cout << "ScavTrap " << this->name << " has no hit points." << std::endl;
    }
    else if (this->energyPoints == 0){
        std::cout << "ScavTrap " << this->name << " has no energy points." << std::endl;
    }
    else {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}