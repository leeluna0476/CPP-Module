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
		~Fixed(void);
		Fixed	&operator =(const Fixed &fixed);

		Fixed(const int &_int);
		Fixed(const float &_float);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator >(const Fixed &fixed) const;
		bool	operator <(const Fixed &fixed) const;
		bool	operator >=(const Fixed &fixed) const;
		bool	operator <=(const Fixed &fixed) const;
		bool	operator ==(const Fixed &fixed) const;
		bool	operator !=(const Fixed &fixed) const;

		Fixed	operator +(const Fixed &fixed) const;
		Fixed	operator -(const Fixed &fixed) const;
		Fixed	operator *(const Fixed &fixed) const;
		Fixed	operator /(const Fixed &fixed) const;

		Fixed		&operator ++();
		Fixed		&operator --();
		const Fixed	operator ++(int);
		const Fixed	operator --(int);

		static	Fixed		&min(Fixed &fixed1, Fixed &fixed2);
		static	Fixed		&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream	&operator <<(std::ostream &os, const Fixed &fixed);

#endif
