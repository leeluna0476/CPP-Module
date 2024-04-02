#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int	value;
		static const int bit = 8;
	
	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed	&operator=(const Fixed &fixed);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
