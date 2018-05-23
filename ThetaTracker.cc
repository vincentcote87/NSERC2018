#include "ThetaTracker.h"

ThetaTracker::ThetaTracker()
   : it{}, Vcount{0}, Vtheta{0.0}, Vprime{}
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
   ++count;
   Vprime = it.next_prime();
   Vtheta += std::log(Vprime);
}
