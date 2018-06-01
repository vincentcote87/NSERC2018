#include <iostream>
#include <primesieve.hpp>
#include "./include/int_double.h"

int main(int argc, char* argv[]) {

	int_double theta = 0.0;
	int_double temp = 0.0;
	int_double y = 0.0;
	int_double errorTerm = 0.0;
	uint64_t start = 0;
	uint64_t stop = 0;
	if(argc > 1) {
		stop = std::stoll(argv[1]);
		if(argc > 2) {
			start = std::stoll(argv[1]);
			stop = std::stoll(argv[2]);
		}
	}

	primesieve::iterator it;
  	it.skipto(start);
  	uint64_t prime = it.next_prime();

  	for (; prime <= stop; prime = it.next_prime()) {
  		temp = theta;
    	y = log(prime) + errorTerm;
    	theta = temp + y;
    	errorTerm = (temp - theta) + y;
  	}

  	print_int_double(theta);
  	std::cout<<std::endl;

	return 0;
}
