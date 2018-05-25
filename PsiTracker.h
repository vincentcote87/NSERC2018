#ifndef PSITRACKER_H
#define PSITRACKER_H

#include <vector>
#include <cmath>
#include <iostream>
#include "ThetaTracker.h"

typedef long long integer;
typedef long double rational;

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
void bringThetaToTarget(const std::vector<integer>&, const integer i);
void populateThetas();
};


#endif //PSITRACKER_H
