#ifndef THETATRACKER_H
#define THETATRACKER_H

#include <primesieve.hpp>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

typedef long long integer;
typedef long double rational;

const integer GAP = 1000 * 1000 * 1000;
const integer INTERVAL = 1000 * 1000;

struct PartialTheta {
   integer start; //exclusive
   integer stop; //inclusive
   rational theta; //partial, betweenx
};

void theta(std::vector<rational>&, const integer, const integer);


#endif
