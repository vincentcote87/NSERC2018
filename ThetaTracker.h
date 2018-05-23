#include <primesieve.hpp>
#include <cmath>

typedef long long integer;
typedef long double rational;

class ThetaTracker {
   primesieve::iterator it;
   integer Vcount;
   rational Vtheta;
   integer Vprime;
  public:
   ThetaTracker();
   integer count();
   integer prime();
   rational theta();
   void next();
   //void setTarget(const integer); //later
}
