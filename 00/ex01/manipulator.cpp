#include <iostream>
#include <iomanip>
#include "manipulator.hpp"

std::ostream	&align_width(std::ostream &ostream)
{
	ostream << std::right << std::setw(10);
	return ostream;
}
