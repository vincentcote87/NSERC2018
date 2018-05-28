#include <iostream>
#include <iomanip>
#include <chrono>

#include "PsiTracker.h"

const int PRECISION = 40;

int main() {
   	long long stoppoint;
	std::cin >> stoppoint;
	std::cout << "runtime,n,prime,theta,psi" << std::endl;
    for (long long a = 1; a <= stoppoint; a*=10) {
        std::chrono::steady_clock clk;
        std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> before = clk.now();
        PsiTracker tracker;
        tracker.next_change();
        while (tracker.prime() < a) {
            std::cout << tracker.prime() << " < " << a << std::endl;
            tracker.next_change();
        }
        long long runtime = (std::chrono::duration_cast<std::chrono::milliseconds>(clk.now()-before)).count();
        std::cout << runtime << ',' << tracker.count() << ',' << tracker.prime() << ',' << std::fixed << std::setprecision(PRECISION) << tracker.theta() << ',' << std::fixed << std::setprecision(PRECISION) << tracker.psi() << std::endl;
    }
    return 0;
}
