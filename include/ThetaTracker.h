#ifndef THETATRACKER_H
#define THETATRACKER_H

#include <primesieve.hpp>
#include <cmath>

typedef long long integer;
typedef long double rational;

class ThetaTracker {
   primesieve::iterator* it;
   integer Vcount;
   rational Vtheta;
   rational VprevTheta;
   integer VprevPrime;
   integer Vprime;
  public:
   ThetaTracker();
   integer count();
   integer prime();
   rational theta();
   void next();
   //can only call previous one time. (It will do nothing if called more than once)
   void previous();
};


#endif
