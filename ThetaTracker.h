#ifndef THETATRACKER_H
#define THETATRACKER_H

#include <primesieve.hpp>
#include <cmath>

typedef long long integer;
typedef long double rational;

class ThetaTracker {
   primesieve::iterator it;
   integer Vcount;
   rational Vtheta;
   rational VprevTheta;
   integer Vprime;
  public:
   ThetaTracker();
   integer count();
   integer prime();
   rational theta();
   void next();
   //can only call previous one time.
   rational previous();
   //void setTarget(const integer); //later
};

#include "ThetaTracker.cc"

#endif
