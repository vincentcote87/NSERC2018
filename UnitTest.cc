#include <primecount.hpp>
#include <iostream>
#include <iomanip>
#include <chrono>

#include "PsiTracker.h"

const int PRECISION = 40;

/*
void testPsiTracker() {
    integer a;
	std::cin >> a;
	PsiTracker tracker;
	tracker.next();
	std::cout << "n,prime,theta,psi" << std::endl;
	while (true) {
		tracker.next();
		if (tracker.prime() > a)
			break;
		std::cout << tracker.count() << ',' << tracker.prime() << ',' << std::fixed << std::setprecision(PRECISION) << tracker.theta() << ',' << std::fixed << std::setprecision(PRECISION) << tracker.psi() << std::endl;
		}
}
*/

int main() {
   	std::cout << "runtime,n,prime,theta,psi" << std::endl;
    for (long long a = 1; a < 1000000000; a*=10) {
        std::chrono::steady_clock clk;
        std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> before = clk.now();
        PsiTracker tracker;
        tracker.next();
        while (tracker.prime() < a) {
            tracker.next();
        }
        long long runtime = (std::chrono::duration_cast<std::chrono::milliseconds>(clk.now()-before)).count();
        std::cout << runtime << ',' << tracker.count() << ',' << tracker.prime() << ',' << std::fixed << std::setprecision(PRECISION) << tracker.theta() << ',' << std::fixed << std::setprecision(PRECISION) << tracker.psi() << std::endl;
    }
    return 0;
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
