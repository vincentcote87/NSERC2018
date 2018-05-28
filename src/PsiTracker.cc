#include "PsiTracker.h"
 
PsiTracker::PsiTracker()
   : tracker{}
{}

void PsiTracker::bringThetaToTarget(const integer cur_x, const integer i) {
   while (tracker[i].prime() < cur_x) {
	    tracker[i].next();
	 }
   if (tracker[i].prime() > cur_x)
      tracker[i].previous();
}

void PsiTracker::next() {
   ++of;
}

void PsiTracker::next_change() {
   //This could be optimized better by looking only at prime powers
   //which would fit better in the overall program
   const rational last = psi();
   do {
      ++of;
   } while (psi() == last);
}

integer PsiTracker::count() {
   return tracker[0].count();
}

integer PsiTracker::prime() {
   return tracker[0].prime();
}

rational PsiTracker::theta() {
   return tracker[0].theta();
}

void PsiTracker::populateThetas() {
   integer cur_x;
   for (size_t i = 0; (cur_x = std::pow(of, 1.0/((rational) i+1))) >= 2; ++i) {
      if (tracker.size() <= i) {
	 tracker.push_back(ThetaTracker{});
	 tracker[i].next();
      }
      bringThetaToTarget(cur_x, i);
   }
}

rational PsiTracker::psi() {
   populateThetas();
   //tracker contains the closest prime thetas less than or equal to the target
   rational psi = 0.0;
   for (size_t i = 0; i < tracker.size(); ++i) { //incorrect
      psi += tracker[i].theta();
   }
   return psi;
}
