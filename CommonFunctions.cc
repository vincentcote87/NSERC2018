
CommonFunctions::pi (integer& ret, const integer x) {
   auto spot = std::find(population.begin(), population.end(), x);
   if (spot == population.end()) {
      //calculate more primes
      
   } else if (*spot == x) {
      //simple case
      ret = std::distance(population.begin(), spot)
   } else { //past x
      //x was not a prime, give one less than x
      if (x < 2)
	 ret = 0.0;
      else {
	 pi(ret, *population.rbegin());
      }
   }
}

CommonFunctions::theta (rational& ret, const integer x) {
   auto spot = std::find(population.begin(), population.end(), x);
   if (spot == population.end()) {
      //calculate more primes
      
   } else if (*spot == x) {
      //simple case
      long double t = 0.0;
      for (auto i = population.begin(); i != spot; ++i) {
	 t += std::log(*i);
      }
      ret = t;
   } else { //past x
      //x was not a prime, give one less than x
      if (x < 2)
	 ret = 0.0;
      else {
	 theta(ret, *population.rbegin());
      }
   }
}

void psi (rational& ret, const integer x) {
   auto spot = std::find(population.begin(), population.end(), x);
   if (spot == population.end()) {
      //calculate more primes
      
   } else if (*spot == x) {
      //simple case
      long double t = 0.0;
      for (auto i = population.begin(); i != spot; ++i) {
	 t += std::floor(std::log(x)/std::log(*i));
      }
      ret = t;
   } else { //past x but not on the end
      //x was not a prime, give one less than x
      if (x < 2)
	 ret = 0.0;
      else {
	 psi(ret, *population.rbegin());
      }
   }
}
