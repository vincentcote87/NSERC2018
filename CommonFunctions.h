#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

typedef long long integer
typedef long double rational

//psi, theta, pi

namespace CommonFunctions {

extern std::vector<integer> population;
   
void pi (integer& ret, const integer x);

void theta (rational& ret, const integer x);

void psi (rational& ret, const integer x);

void calculate (integer& ret, const integer x, void (*)(integer&, const integer));

void calculate (rational& ret, const integer x, void (*)(rational&, const integer));

void populateUntil(const integer x);

}
