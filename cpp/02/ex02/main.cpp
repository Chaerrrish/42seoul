#include "Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

// int main(void) {
//     Fixed a(5.05f);
//     Fixed b(2);
//     Fixed c;

//     // Testing addition
//     c = a + b;
//     std::cout << "a + b = " << c << std::endl;

//     // Testing subtraction
//     c = a - b;
//     std::cout << "a - b = " << c << std::endl;

//     // Testing multiplication
//     c = a * b;
//     std::cout << "a * b = " << c << std::endl;

//     // Testing division
//     c = a / b;
//     std::cout << "a / b = " << c << std::endl;

//     // Testing comparison operators
//     std::cout << "a > b: " << (a > b) << std::endl;
//     std::cout << "a < b: " << (a < b) << std::endl;
//     std::cout << "a >= b: " << (a >= b) << std::endl;
//     std::cout << "a <= b: " << (a <= b) << std::endl;
//     std::cout << "a == b: " << (a == b) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;

//     // Testing increment and decrement operators
//     std::cout << "Initial value of a: " << a << std::endl;
//     std::cout << "Prefix increment: " << ++a << std::endl;
//     std::cout << "Postfix increment: " << a++ << std::endl;
//     std::cout << "Value of a after postfix increment: " << a << std::endl;

//     std::cout << "Prefix decrement: " << --a << std::endl;
//     std::cout << "Postfix decrement: " << a-- << std::endl;
//     std::cout << "Value of a after postfix decrement: " << a << std::endl;

//     // Testing min and max functions
//     std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
//     std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;

//     return 0;
// }

