#include "PsiTracker.h"

PsiTracker::PsiTracker()
   : tracker{}
{}

void PsiTracker::bringThetaToTarget(const std::vector<integer>& target, const int i) {
   while (tracker[i].prime() < target[i]) {
	    tracker[i].next();
	 }
	 if (tracker[i].prime() > target[i])
	    tracker[i].previous();
}

void PsiTracker::next() {
   if (tracker.empty()) {
      tracker.push_back(ThetaTracker{});
      std::cout << "We got to this spot" << std::endl;
      if (tracker.empty())
         std::cout << "wtf" << std::endl;
      tracker.begin()->next();
      return;
   }
   std::vector<integer> target_x;
   target_x.push_back(tracker.begin()->prime());
   integer cur_x;
   for (size_t i = 1; (integer) std::pow(cur_x = tracker.begin()->prime() >= 2, i+1); ++i) {
      target_x.push_back(cur_x);
   }
   for (int i = 0; i < target_x.size(); ++i) {
      if (tracker.size() <= i) {
	 tracker.push_back(ThetaTracker{});
	 tracker[i].next();
      }
      bringThetaToTarget(target_x, i);
   }
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

rational PsiTracker::psi() {
   //tracker contains the closest prime thetas less than or equal to the target
   rational psi = 0.0;
   for (int i = 0; i < tracker.size(); ++i) { //incorrect
      psi += tracker[i].theta();
   }
   return psi;
}
