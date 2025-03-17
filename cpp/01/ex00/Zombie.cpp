#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->name = name;
	std::cout<<this->name<<": Hi i am Zombie..."<<std::endl;
}

Zombie::~Zombie()
{
	std::cout<<this->name<<": Dieeeeeeee..."<<std::endl;
}

void	Zombie::announce( void )
{
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}