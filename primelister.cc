//This is intended to run in the background, generating a database of prime numbers

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <primesieve.hpp>

typedef long long integer;
typedef long double rational;

const integer MAXLEN = 20; //log2^64 / log10

size_t getMax() {
    size_t min = 0;
    return min - ((size_t) 1);
}

void program (const std::string outputPath, const size_t endpoint) {
    std::chrono::steady_clock clk;
    auto began = clk.now();
    primesieve::iterator it;
    std::ofstream o;
    o.open(outputPath);
    for (size_t i = 0; i < endpoint; ++i) {
        switch(i) {
        case 1u:
        case 10u:
        case 100u:
        case 1000u:
        case 10000u:
        case 100000u:
        case 1000000u:
        case 10000000u:
        case 100000000u:
        case 1000000000u:
        case 10000000000u:
        case 100000000000u:
        case 1000000000000u:
        case 10000000000000u:
        case 100000000000000u:
        case 1000000000000000u:
        case 10000000000000000u:
        case 100000000000000000u:
        case 1000000000000000000u:
        case 10000000000000000000u:
            std::cout << "Have done: " << i << "prime numbers" << std::endl;
            std::cout << "It took " << std::chrono::duration_cast<std::chrono::milliseconds>(clk.now()-began).count() << " milliseconds." << std::endl;
        default:
            o << std::fixed << std::setfill(' ') << std::setw(MAXLEN) << std::left << it.next_prime() << std::endl;
            break;
        }
    }
    std::cout << "Finished.\n";
    std::cout << "It took " << std::chrono::duration_cast<std::chrono::milliseconds>(clk.now()-began).count() << " milliseconds." << std::endl;
}

int main(const int N, const char* arg_in[]) {
    std::string output;
    size_t maximum;
    switch (N) {
        case 1:
            std::cout << "Please specify an output path: ";
            std::cin >> output;
        case 2:
            std::cout << "Using " << getMax() << " as the stopping point.\n";
            std::cout << "(The maximum value of size_t)" << std::endl;
            maximum = getMax();
        case 3:
            break;
        default:
            std::cout << "Too many arguments." << std::endl;
            return 0;
    }
    switch (N) {
        case 3:
            maximum = std::atoll(arg_in[2]);
        case 2:
            output = arg_in[1];
        case 1:
            break;
    }
    program(output, maximum);
    return 0;
}
