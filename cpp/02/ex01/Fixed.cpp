#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed( const int value )
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value << bits;
}

Fixed::Fixed( const float value )
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << bits)); //cmath
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& Fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = Fixed;
}

Fixed&  Fixed::operator=(const Fixed &Fixed)
{
    std::cout<< "Copy assignment operator called" <<std::endl;
    this->value = Fixed.getRawBits();
    return *this;
}

int     Fixed::getRawBits( void ) const
{
    // std::cout<< "getRawBits member function called" <<std::endl;
    return value;
}

void    Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

float	Fixed::toFloat( void ) const
{
    return ((float)value / (1 << bits)); 
}

int		Fixed::toInt( void ) const
{
    return (roundf((float)value / 256)); 
}

std::ostream&	operator<<(std::ostream& out, const Fixed& Fixed)
{
	out << Fixed.toFloat();
	return out;
}