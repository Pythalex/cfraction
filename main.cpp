#include <iostream>
#include <string>

#include "cfraction.h"

void cfraction_test() {
	cfraction fraction1(8,-1);
	cfraction fraction2(4,8);
	cfraction fraction3(1,2);

	// Afficher fractions
	std::cout << fraction1 << std::endl;
	std::cout << fraction2 << std::endl;
	std::cout << fraction3 << std::endl << std::endl;

	// Operateurs arithmétiques classiques
	std::cout << "Operateurs arithmetiques classiques" << std::endl;
	std::cout << fraction2 << " + " << fraction3 << " = " << fraction2 + fraction3 << std::endl;
	std::cout << fraction1 << " - " << fraction2 << " - " << fraction3 << " = " << fraction1 - fraction2 - fraction3 << std::endl;
	std::cout << fraction2  << " * " << fraction3 << " = " << fraction2 * fraction3 << std::endl;
	std::cout << fraction1  << " / " << fraction3 << " = " << fraction1 / fraction3 << std::endl << std::endl;
	std::cout << std::endl;
	std::cout << "(avec des int)" << std::endl;
	std::cout << fraction1 << " + " << 5 << " = " << fraction1 + 5 << std::endl;
	std::cout << fraction3 << " + " << -2 << " = " << fraction1 + (-2) << std::endl;
	std::cout << std::endl;

	// Operateurs arithmétiques raccourcis
	std::cout << "Operateurs arithmetiques raccourcis" << std::endl;
	std::cout << fraction1 << " += " << fraction2 << " --> ";
	fraction1 += fraction2;
	std::cout << fraction1 << std::endl;
	std::cout << fraction1 << " -= " << fraction2 << " --> ";
	fraction1 -= fraction2;
	std::cout << fraction1 << std::endl;
	std::cout << fraction1 << " *= " << fraction2 << " --> ";
	fraction1 *= fraction2;
	std::cout << fraction1 << std::endl;
	std::cout << fraction1 << " /= " << fraction2 << " --> ";
	fraction1 /= fraction2;
	std::cout << fraction1 << std::endl << std::endl;

	// Operateurs de comparaison
	std::cout << "Operateurs de comparaison" << std::endl;
	std::cout << fraction2 << " == " << fraction3 << " = " << (fraction2 == fraction3 ? "true" : "false") << std::endl;
	std::cout << fraction1 << " < " << fraction3 << " = " << (fraction1 < fraction3 ? "true" : "false") << std::endl;
	std::cout << fraction1 << " > " << fraction3 << " = " << (fraction1 > fraction3 ? "true" : "false") << std::endl;
}


int main() {

	/// FOR DEBUG BEGIN
	std::cout << "=== DEBUG PROGRAM ===\n" << std::endl;
	// Tests
	cfraction_test();
	std::cout << std::endl;
	std::cout << "===      END      ===\n";
	/// FOR DEBUG END

	// Anti-exit
	std::cin.get();
	return 0;
}