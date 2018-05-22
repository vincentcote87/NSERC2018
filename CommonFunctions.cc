
void CommonFunctions::populateUntil(const integer x) {
   integer i = CommonFunctions::population.size() + 1; // empty + 1 = 1
      do {
	 integer ithprime = nth_prime(i++);
	 CommonFunctions::population.push_back(ithprime);
      } while (ithprime < x);
}

void CommonFunctions::calculate(integer& ret, const integer x, void (*func)(integer&, const integer)) {
   if (x < 2)
      ret = 0.0; //so far so true (we only do psi, theta and pi)
   else {
      CommonFunctions::populateUntil(x);
      func(ret, x);
   }
}

void CommonFunctions::calculate(rational& ret, const integer x, void (*func)(rational&, const integer)) {
   if (x < 2)
      ret = 0.0; //so far so true (we only do psi, theta and pi)
   else {
      CommonFunctions::populateUntil(x);
      func(ret, x);
   }
}

void CommonFunctions::pi (integer& ret, const integer x) {
   for (ret = 0; CommonFunctions::population[ret] <= x; ++ret);
   //stops when is greater than x. If x is not prime then minus one, x is prime minus one
   //need to add one because of indexing 2 at zero
}

void CommonFunctions::theta (rational& ret, const integer x) {
   ret = 0.0;
   size_t i = 0;
   while ((const integer prime = CommonFunctions::populations[i]) <= x) {
      ret += std::log(prime);
   }
}

void CommonFunctions::psi (rational& ret, const integer x) {
   ret = 0.0;
   size_t i = 0;
   while ((const integer prime = CommonFunctions::populations[i]) <= x) {
      ret += std::floor(std::log(x)/std::log(prime));
   }
}
