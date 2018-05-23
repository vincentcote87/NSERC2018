#include <primecount.hpp>
#include <iostream>
#include <iomanip>

#include "ThetaTracker.h"

int main() {
	integer a;
	std::cin >> a;
	ThetaTracker tracker;
	std::cout << "n,prime,theta" << std::endl;
	while (true) {
		tracker.next();
		if (tracker.prime() > a)
			break;
		std::cout << tracker.count() << ',' << tracker.prime() << ',' << std::fixed << std::setprecision(16) << tracker.theta() << std::endl;
	} 
}

/*
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
*/
