#include <iostream>
#include <primesieve.hpp>
#include <chrono>
#include "./include/int_double.h"

int main(int argc, char* argv[]) {
   std::chrono::steady_clock clk;
   std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration> before = clk.now();
   
   //int_double theta = 0.0;
   //int_double temp = 0.0;
   //int_double y = 0.0;
   //int_double errorTerm = 0.0;
   uint64_t start = 0;
   uint64_t stop = 0;
   uint64_t gap = 0;
   uint64_t stopgap;

   if(argc > 1) {
      stop = std::stoll(argv[1]);
      gap = stop - start;
      if(argc > 2) {
	 start = std::stoll(argv[1]);
	 stop = std::stoll(argv[2]);
	 gap = stop - start;
	 if (argc > 3) {
	    gap = std::stoll(argv[3]);
	 }
      }
   }
   
   primesieve::iterator it;
   it.skipto(start);
   uint64_t firstChangePrime, lastChangePrime;
   uint64_t prime = firstChangePrime = it.next_prime();
   uint64_t startgap;

   //issues: Now we only know on the STOPGAPS, not the STOP, since STOPGAP can exceed STOP and it just quits.
   for (startgap = start; prime <= stop; startgap = stopgap) {
      int_double theta = 0.0;
      int_double temp = 0.0;
      int_double y = 0.0;
      int_double errorTerm = 0.0;
      for (stopgap = startgap + gap; prime <= stopgap; prime = it.next_prime()) {
	 lastChangePrime = prime;
	 temp = theta;
	 y = static_cast<int_double>(log(prime)) + errorTerm;
	 theta = temp + y;
	 errorTerm = (temp - theta) + y;
      }
      long long ms = (std::chrono::duration_cast<std::chrono::milliseconds>(clk.now()-before)).count();
      //       runtime  ,              parameters   ,                bounding changes              ,
      std::cout << ms << ',' << startgap << ',' << stopgap << ',' << firstChangePrime << ',' << lastChangePrime << ',';
      print_int_double(theta); //inteval real
      std::cout<<std::endl; //no endline character? Then the file is not good.
   }
   return 0;
}
