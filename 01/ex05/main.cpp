#include "Harl.hpp"

int main (void)
{	
	Harl harl;

	harl.complain("Debug");
	harl.complain("Info");
	harl.complain("Warning");
	harl.complain("Error");
	harl.complain("??");

	return 0;
}
