#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
    std::cout << "ScalarConverter :: Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter :: Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& ScalarConverter)
{
    *this = ScalarConverter;
    std::cout << "ScalarConverter :: Copy Constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ScalarConverter)
{
    if (this != &ScalarConverter){
        std::cout << "ScalarConverter :: Copy assignment operator called" << std::endl;
    }
    return *this;
}

void ScalarConverter::convert(std::string str)
{
    const char* cstr = str.c_str();
    char* endptr;
    double num;

   
    num = std::strtod(cstr, &endptr);

    if (!(endptr[0] == 0 || endptr[0] == 'f')) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    std::cout << "char: ";
    if (num < 32 && !(num > 2147483647 || num < -2147483648 || num!=num || num < 0))
		std::cout << "Non displayable" << std::endl;
	else if (!isprint(num) || num < 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(num) << "\'" << std::endl;
    
    std::cout << "int: ";
    if (num > 2147483647 || num < -2147483648 || num!=num)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
    
    std::cout << "float: ";
    if (num!=num)
		std::cout << "nanf" << std::endl;
	else
    {
		std::cout << static_cast<float>(num);
        if (static_cast<float>(num) - static_cast<int>(num) == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    std::cout << "double: ";
    if (num!=num)
		std::cout << "nan" << std::endl;
	else
    {
		std::cout << num;
        if (num - static_cast<int>(num) == 0)
            std::cout << ".0";
        std::cout<<std::endl;
    }
}