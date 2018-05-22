#include <primecount.hpp>
#include <iostream>

int main() {
    for (int i = 1; i <= 10; ++i) {
        std::cout << 
        primecount::pi(i) << ' ';
    }
    std::cout << std::endl;
    return 0;
}
