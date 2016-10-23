#include <iostream>
#include <string>

#include "cfraction.h"

void cfraction_test() {
	cfraction fraction1(8,2);
	cfraction fraction2(4,8);
	cfraction fraction3(1,2);

	std::cout << fraction2 + fraction3 << std::endl;
	std::cout << fraction1 - fraction2 - fraction3 << std::endl;
	std::cout << fraction2 * fraction3 << std::endl;
	std::cout << fraction1 / fraction3 << std::endl;
}


int main() {

	/// FOR DEBUG BEGIN
	std::cout << "=== DEBUG PROGRAM ===\n";
	// Tests
	cfraction_test();
	/// FOR DEBUG END

	// Anti-exit
	std::cin.get();
	return 0;
}