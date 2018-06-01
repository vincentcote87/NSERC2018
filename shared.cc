#include "shared.h"

integer shared::pow(const integer a , const integer b) {
   if (b == 0)
      return 1;
   if (b % 2)
      return pow(a, b/2) * pow(a, b/2) * a;
   else
      return pow(a, b/2) * pow(a, b/2);
}

rational shared::ator(const std::string& a) {
   int i = 0;
   for (; i < a.size() && a[i] != '.'; ++i);
   rational top = std::atoll(a.substr(0, i).c_str());
   rational bottom = ((rational) std::atoll(a.substr(i+1, a.size()).c_str())) /
      (
	 (rational) shared::pow( (integer) 10, (integer) (a.size() - (i + 1)))
	 ) ;
   return top + bottom;
}
