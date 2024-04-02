#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int	value;
		static const int bit = 8;
	
	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed	&operator =(const Fixed &fixed);
		~Fixed(void);

		Fixed(const int &_int);
		Fixed(const float &_float);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator >(const Fixed &fixed);
		bool	operator <(const Fixed &fixed);
		bool	operator >=(const Fixed &fixed);
		bool	operator <=(const Fixed &fixed);
		bool	operator ==(const Fixed &fixed);
		bool	operator !=(const Fixed &fixed);

		float	operator +(const Fixed &fixed);
		float	operator -(const Fixed &fixed);
		float	operator *(const Fixed &fixed);
		float	operator /(const Fixed &fixed);

		Fixed	&operator ++();
		Fixed	&operator --();
		Fixed	operator ++(int);
		Fixed	operator --(int);
};

std::ostream	&operator <<(std::ostream &os, const Fixed &fixed);

#endif
