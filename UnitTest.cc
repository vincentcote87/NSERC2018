#include <primecount.hpp>
#include <iostream>

#include "CommonFunctions.h"

int main() {
	std::cout << primecount::nth_prime(6) << std::endl;
	integer number, x;
	rational fraction;
	while (true) {
		std::cout << "Caculate: " ;
		std::cin >> x;
		
		CommonFunctions::calculate(number, x, CommonFunctions::pi);
		std::cout << "pi(x) = " << number << std::endl;
		CommonFunctions::calculate(fraction, x, CommonFunctions::theta);
		std::cout << "theta(x) = " << fraction << std::endl;
		CommonFunctions::calculate(fraction, x, CommonFunctions::psi);
		std::cout << "psi(x) = " << fraction << std::endl;
	}
}
