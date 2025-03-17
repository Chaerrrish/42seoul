#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>

class RPN {
	private:
		std::stack<int> s;

	public:
		RPN();
		~RPN();
		RPN(const RPN& rpn);
		RPN& operator=(const RPN& rpn);

		int calculate(std::string input);
		int isDigit(char c);
		int isOperator(const char c);
	
};

#endif