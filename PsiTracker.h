#ifndef PSITRACKER_H
#define PSITRACKER_H

#include <vector>
#include <cmath>
#include "ThetaTracker.h"

class PsiTracker {
   std::vector<ThetaTracker> tracker;
  public:
   PsiTracker();
   void next();
   integer count();
   integer prime();
   rational theta();
rational psi();
private:
void bringThetaToTarget();
};

#include "PsiTracker.cc"

#endif //PSITRACKER_H
