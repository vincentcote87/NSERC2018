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

void ThetaTracker::next() {
   ++Vcount;
   if (Vtheta > VprevTheta) {
       VprevPrime = Vprime;
       Vprime = it->next_prime();
       VprevTheta = Vtheta;
       Vtheta += std::log(Vprime); 
   } else {
      std::swap(Vprime, VprevPrime);
      std::swap(Vtheta, VprevTheta);
   }
}

void ThetaTracker::previous() {
   if (Vtheta > VprevTheta) {
      --Vcount;
      std::swap(Vprime, VprevPrime);
      std::swap(Vtheta, VprevTheta);
   }
}
