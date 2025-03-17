#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed( int value )
{
    // std::cout << "Int constructor called" << std::endl;
    this->value = value << bits;
}

Fixed::Fixed( float value )
{
    // std::cout << "Float constructor called" << std::endl;
    this->value = roundf(value * (1 << bits)); //cmath
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& Fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = Fixed;
}

Fixed&  Fixed::operator=(const Fixed &Fixed)
{
    // std::cout<< "Copy assignment operator called" <<std::endl;
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
    return ((float)value / 256); 
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

bool	Fixed::operator>(const Fixed& Fixed) const
{
    return (this->value > Fixed.value);
}

bool	Fixed::operator<(const Fixed& Fixed) const
{
    return (this->value < Fixed.value);
}

bool	Fixed::operator>=(const Fixed& Fixed) const
{
    return (this->value >= Fixed.value);
}

bool	Fixed::operator<=(const Fixed& Fixed) const
{
    return (this->value <= Fixed.value);
}

bool	Fixed::operator==(const Fixed& Fixed) const
{
    return (this->value == Fixed.value);
}

bool	Fixed::operator!=(const Fixed& Fixed) const
{
    return (this->value != Fixed.value);
}

Fixed	Fixed::operator+(const Fixed &ref)
{
    Fixed temp(this->toFloat() + ref.toFloat());
    return temp;
}

Fixed	Fixed::operator-(const Fixed &ref)
{
    Fixed temp(this->toFloat() - ref.toFloat());
    return temp;
}

Fixed	Fixed::operator*(const Fixed &ref)
{
    Fixed temp(this->toFloat() * ref.toFloat());
    return temp;
}

Fixed	Fixed::operator/(const Fixed &ref)
{
    Fixed temp(this->toFloat() / ref.toFloat());
    return temp;
}

Fixed&	Fixed::operator++(void) //++a
{
    value++;
    return *this;
}

const Fixed	Fixed::operator++(int) //a++
{
    const Fixed temp(*this);
    value++;
    return temp;
}

Fixed&	Fixed::operator--(void)
{
    value--;
    return *this;
}

const Fixed	Fixed::operator--(int)
{
    const Fixed temp(*this);
    value--;
    return temp;
}

Fixed&		Fixed::min(Fixed& a, Fixed& b)
{
    return (a <= b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a <= b ? a : b);
}

Fixed&		Fixed::max(Fixed& a, Fixed& b)
{
    return (a >= b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a >= b ? a : b);
}