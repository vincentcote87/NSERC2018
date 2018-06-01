//#include <primesieve.hpp>
#include <primesieve.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "shared.h"

integer start;
integer stop;

//exclusive start inclusive stop

const int PRECISION = 53;

int main(int N, char* arg[]) {
   if (N == 2) {
      stop = std::atoll(arg[1]);
      start = 1;
   }
   if (N == 3) {
      start = std::atoll(arg[1]);
      stop = std::atoll(arg[2]);
   }
   primesieve::iterator it;
   it.skipto(start);
   rational result = 0.0;
   integer prime, pb, pe;
   //start exclusively, stop inclusively
   for (pb = prime = it.next_prime(); prime <= stop; prime = it.next_prime()) {
      pe = prime;
      result += std::log(prime);
   }
   std::cout << start << ", " << stop << ":\n"; //ex, inc bounds
   std::cout << pb << ", " << pe << std::endl; //inc, ex bounds
   std::cout << std::fixed << std::setprecision(PRECISION) << result << std::endl;
   std::cout << std::fixed << std::setprecision(PRECISION) << std::endl;
}
