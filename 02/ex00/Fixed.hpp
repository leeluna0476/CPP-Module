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
		void operator=(Fixed &fixed);
		~Fixed(void);
};

#endif
