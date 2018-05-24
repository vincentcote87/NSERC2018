#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

#include "PsiTracker.h"

int main() {
   cout << "Calculate values on a prime >= ";
   long long a;
   cin >> a;
   std::chrono::steady_clock clk;
        std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> before = clk.now();
   PsiTracker tracker;
   tracker.next();
   std::cout << "n,prime,theta,psi" << std::endl;
   while (tracker.prime() < a) {
      tracker.next();
   }
   long long runtime = (std::chrono::duration_cast<std::chrono::milliseconds>(clk.now()-before)).count();
   cout << "runtime: " << runtime << " miliseconds" << endl;
   cout << "pi: " << tracker.count() << endl;
   cout << "nth prime: " << tracker.prime() << endl;
   cout << "theta: " << std::fixed << std::setprecision(PRECISION) << tracker.theta();
   cout << "psi: " << std::fixed << std::setprecision(PRECISION) << tracker.psi() << std::endl;
   return 0;
}
