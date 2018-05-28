#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>

#include "PsiTracker.h"

const int PRECISION = 40;

int main(int N, char* arg[]) {
   	if (N != 3) {
   	    std::cout << "     Usage:\n  " << arg[0] << " stoppoint multiplyby" << std::endl;
   	}
   	const long long stoppoint = std::atoll(arg[1]);
   	const long long multiplyby = std::atoll(arg[2]);
	std::cout << "runtime,n,prime,theta,psi" << std::endl;
    for (long long a = 1; a <= stoppoint; a*=multiplyby) {
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
