#include <iostream>
#include <iomanip>
#include "shared.h"


bool test_pow() {
	integer a, b, c;
	a = 3;
	b = 3;
	c = shared::pow(a, b);
	if (c != 27)
	   return false;
	a = 0;
	b = 0;
	c = shared::pow(a, b);
	if (c != 1)
	   return false;
	a = 10;
	b = 8;
	c = shared::pow(a, b);
	if (c != 100000000)
	   return false;
	return true;
}

bool test_ator() {
   char c[] = "1234.12345678909876";
   rational rat = shared::ator(c);
   std::cout << std::fixed << std::setprecision(40) << rat << std::endl;
   std::cout << (rat > 1234.1234567890987) << ' ' << (rat < 1234.12345678909877);
   std::cout << std::endl;
   return 1234.1234567890986 < rat && rat < 1234.12345678909877;
   //return rat > 1234.12345678909876 - 0.00000000000001 && rat < 1234.12345678909876 + 0.00000000000001;
}

int main() {
   if (test_ator())
      std::cout << "ator passed." << std:: endl;
   else
      std::cout << "ator fail." << std::endl;
   if (test_pow())
      std::cout << "pow passed." << std::endl;
   else
      std::cout << "pow fail." << std::endl;
}
