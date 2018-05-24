#include "ThetaTracker.h"

ThetaTracker::ThetaTracker()
   : it{new primesieve::iterator{}}, Vcount{0}, Vtheta{0.0}, VprevTheta{}, Vprime{}
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
   Vprime = it->next_prime();
   VprevTheta = Vtheta;
   Vtheta += std::log(Vprime);
}

rational ThetaTracker::previous() {
   if (Vtheta != VprevTheta) {
      --Vcount;
      Vprime = it->prev_prime();
      Vtheta = VprevTheta;
   }
}
