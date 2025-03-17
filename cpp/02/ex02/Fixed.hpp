#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;

	public:
		Fixed();
		Fixed( int value );
		Fixed( float value );
		~Fixed();
		Fixed(const Fixed &Fixed);
		Fixed&	operator=(const Fixed &Fixed);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator>(const Fixed& Fixed) const;
		bool	operator<(const Fixed& Fixed) const;
		bool	operator>=(const Fixed& Fixed) const;
		bool	operator<=(const Fixed& Fixed) const;
		bool	operator==(const Fixed& Fixed) const;
		bool	operator!=(const Fixed& Fixed) const;

		Fixed	operator+(const Fixed &Fixed);
		Fixed	operator-(const Fixed &Fixed);
		Fixed	operator*(const Fixed &Fixed);
		Fixed	operator/(const Fixed &Fixed);

		Fixed&	operator++(void); //++a
		const Fixed	operator++(int); //a++
		Fixed&	operator--(void);
		const Fixed	operator--(int);

		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& Fixed);

#endif