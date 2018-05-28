#include "PsiTracker.h"
 
PsiTracker::PsiTracker()
   : tracker{}
{
    of = 1;
}

void PsiTracker::bringThetaToTarget(const integer cur_x, const integer i) {
   while (tracker[i].prime() < cur_x) {
        tracker[i].next();
	    std::cout << tracker[i].prime() << ' ';
	 }
	 std::cout << std::endl;
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
   std::cout << "Found next change: " << of << ", " << prime() << std::endl;
}

integer PsiTracker::count() {   
   if (tracker.empty())
      return 0;
   return tracker[0].count();
}

integer PsiTracker::prime() {
   if (tracker.empty())
      return 1;
   return tracker[0].prime();
}

rational PsiTracker::theta() {
   if (tracker.empty())
      return 0;
   return tracker[0].theta();
}

void PsiTracker::populateThetas() {
   integer cur_x;
   for (size_t i = 0; (cur_x = std::pow(of, 1.0/((rational) i+1))) >= 2; ++i) {
      std::cout << "cur_x: " << cur_x << " i: " << i << " tracker.size(): " << tracker.size() << std::endl;
      if (tracker.size() <= i) {
	 tracker.push_back(ThetaTracker{});
	 tracker[i].next();
      }
      std::cout << "About to call bringThetaToTarget" << std::endl;
      if (tracker.empty())
        continue;
      bringThetaToTarget(cur_x, i);
   }
}

rational PsiTracker::psi() {
    std::cout << "Entered Psi." << std::endl;
   populateThetas();
   std::cout << "Populated Thetas" << std::endl;
   //tracker contains the closest prime thetas less than or equal to the target
   rational psi = 0.0;
   for (size_t i = 0; i < tracker.size(); ++i) {
      psi += tracker[i].theta();
   }
   return psi;
}
