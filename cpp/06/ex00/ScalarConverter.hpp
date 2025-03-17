#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cfloat>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& ScalarConverter);
        ScalarConverter& operator=(const ScalarConverter& ScalarConverter);

    public:
        ~ScalarConverter();
        
        static void convert(std::string str);
};

#endif