#include <iomanip>
#include "manipulator.hpp"

std::ostream	&align_width(std::ostream &cout)
{
	cout << std::right << std::setw(10);
	return cout;
}
