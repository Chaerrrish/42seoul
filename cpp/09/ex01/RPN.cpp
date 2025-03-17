#include "RPN.hpp"

RPN::RPN()
{
	// std::cout << "RPN :: Constructor called" << std::endl;
}

RPN::~RPN()
{
	// std::cout << "RPN :: Destructor called" << std::endl;
}

RPN::RPN(const RPN& rpn)
{
	*this = rpn;
	// std::cout << "RPN :: RPN Copy Constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN& rpn)
{
	if (this != &rpn) {
		this->s = rpn.s; 
	}
	return *this;
}

int RPN::isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int RPN::isOperator(const char c)
{
	if (c == '*' || c == '+' || c == '-' || c == '/')
		return 1;
	return 0;
}


int RPN::calculate(std::string input)
{
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
		{
			i++;
			continue;
		}
		if (input[i] == '(' || input[i] == ')')
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		if (isDigit(input[i]))
			s.push(input[i] - '0');
		else if (isOperator(input[i]))
		{
			int a;
			int b;
			if (s.size() >= 2)
			{
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
			}
			else {
				std::cout << "Error" << std::endl;
				exit(1);
			}
			if (input[i] == '+')
				s.push(b + a);
			else if (input[i] == '-')
				s.push(b - a);
			else if (input[i] == '*')
				s.push(b * a);
			else if (input[i] == '/')
				s.push(b / a);
		}
		else {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		i++;
	}
	int result = s.top();
	s.pop();
	if (s.size() > 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
	return result;
}
