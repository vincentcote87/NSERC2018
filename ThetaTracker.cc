#include "ThetaTracker.h"

ThetaTracker::ThetaTracker()
   : it{new primesieve::iterator{}}, Vcount{0}, Vtheta{0.0}, VprevTheta{}, VprevPrime{}, Vprime{}
{}

integer ThetaTracker::count() {
   return Vcount;
}

integer ThetaTracker::prime() {
   return Vprime;
}

rational ThetaTracker::theta() {
   return Vtheta;
}

#include <iostream>

void ThetaTracker::next() {
   ++Vcount;
   VprevPrime = Vprime;
   Vprime = it->next_prime();
   VprevTheta = Vtheta;
   Vtheta += std::log(Vprime);
}

void ThetaTracker::previous() {
   if (Vtheta != VprevTheta) {
      --Vcount;
      Vprime = VprevPrime;
      Vtheta = VprevTheta;
   }
}
