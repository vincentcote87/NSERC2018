#include <primesieve.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

int main(void) {
	uint64_t x;
	uint64_t count = 1;
	long double theta = 0.0;
	long double sumOverP = 0.0;
	long double sumOverLogP = 0.0;
	std::ofstream file;
	file.open("list.csv");

	std::cout<<"Enter a value for x: ";
	std::cin>>x;

	file<<"n, nth Prime, Theta, log(p)/p, 1/p"<<std::endl;

	std::vector<int> primes;
  	primesieve::generate_primes(1000, &primes);

  	primesieve::iterator it;
  	uint64_t prime = it.next_prime();

  	for (; prime < x; prime = it.next_prime()) {
  		theta += log(prime);
  		sumOverP += 1.0/prime;
  		sumOverLogP += log(prime)/prime;
  		file<<count<<","<<prime<<","<<std::setprecision(30)<<theta<<","<<std::setprecision(30)<<sumOverLogP<<","<<std::setprecision(30)<<sumOverP<<std::endl;
  		count++;
  	}
	return 0;
}