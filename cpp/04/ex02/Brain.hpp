#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{
	public:
		Brain();
		Brain(std::string*  idea);
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		~Brain();
		void printIdeas() const;

	private:
		std::string ideas[100];
};

#endif