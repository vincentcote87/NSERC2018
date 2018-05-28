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
   integer of;
  public:
   PsiTracker();
   void next();
   void next_change();
   integer count();
   integer prime();
   rational theta();
rational psi();
private:
void bringThetaToTarget(const integer, const integer);
void populateThetas();
};


#endif //PSITRACKER_H
