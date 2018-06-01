#include <iostream>
#include <primesieve.hpp>
#include "./include/mpreal.h"

int main(int argc, char* argv[]) {

	const int digits = 50;
	mpfr::mpreal::set_default_prec(mpfr::digits2bits(digits));

	mpfr::mpreal theta = "0.0";
	mpfr::mpreal temp = "0.0";
	mpfr::mpreal y = "0.0";
	mpfr::mpreal errorTerm = "0.0";
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
    	y = log(static_cast<mpfr::mpreal>(prime)) + errorTerm;
    	theta = temp + y;
    	errorTerm = (temp - theta) + y;
  	}

  	std::cout.precision(digits);
  	std::cout<<theta<<std::endl;

	return 0;
}