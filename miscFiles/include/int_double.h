// a simple version of double interval arithmetic that avoids messing
// with rounding modes by doing nextbefore/nextafter after every operation
// may increase interval unnecessarily when results are exact
#ifndef INT_DOUBLE
#define INT_DOUBLE
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <algorithm>
#include "crlibm.h"

using namespace std;

inline double min(const double a, const double b, const double c, const double d)
{
  return std::min(std::min(a,b),std::min(c,d));
}

inline double max(const double a, const double b, const double c, const double d)
{
  return std::max(std::max(a,b),std::max(c,d));
}


double nextbefore(const double);

inline double nextafter (const double x)
{
  if(!isfinite(x)) return nan("");
  if(x==0.0) return DBL_MIN;
  double xx=x;
  uint64_t *i;
  i=(uint64_t *) &xx;
  i[0]+=(x>0.0 ? 1 : -1);
  return xx;
}

inline double nextbefore (const double x)
{
  if(!isfinite(x)) return nan("");
  if(x==0.0) return -DBL_MIN;
  double xx=x;
  uint64_t *i;
  i=(uint64_t *) &xx;
  i[0]+=(x>0.0 ? -1 : 1);
  return xx;
}

// most of the operators aren't defined yet
class int_double{
public:
  double left;
  double right;
	
inline  int_double ()                      // constructors
  {
  };
// does no rounding, see below
inline int_double(double l) 
{
  left=l;
  right=l;
};

// N.B. this default contructor does no rounding.
// Note that the compiler probably rounds to nearest
// e.g. third=1.0/3.0; int_third=int_double(third,third);
//      results in a point interval at nearest to 1/3.
//
// you probably want int_third=int_double(1.0)/3.0;
inline int_double(double l,double r)
{
	
    if(l>r)
    {
	printf("Error constructing int_double, right %20.18e < left %20.18e . Exiting.\n",r,l);
        exit(1);
    };
	
    left=l;
    right=r;
}

   friend int_double operator + (const int_double &lhs, const int_double &rhs);
   friend int_double operator + (const int_double &lhs, const double &rhs);
   friend int_double operator - (const int_double &lhs, const int_double &rhs);
   friend int_double operator - (const int_double &lhs, const double &rhs);
   friend int_double operator - (const int_double &lhs);
   friend int_double operator * (const int_double &lhs, const int_double &rhs);
   friend int_double operator * (const int_double &lhs, const double &rhs);
  friend int_double operator / (const int_double &lhs, const int_double &rhs);
  friend int_double operator / (const int_double &lhs, const double &rhs);
  friend int_double operator += (int_double &lhs, const int_double &rhs);
  friend int_double operator += (int_double &lhs, const double &rhs);
  friend int_double operator -= (int_double &lhs, const int_double &rhs);
  friend int_double operator -= (int_double &lhs, const double &rhs);
  friend int_double operator *= (int_double &lhs, const int_double &rhs);
  friend int_double operator *= (int_double &lhs, const double &rhs);
  friend int_double operator /= (int_double &lhs, const int_double &rhs);
  friend int_double operator /= (int_double &lhs, const double &rhs);
  friend int operator >= (const int_double &lhs, const int_double &rhs);
  friend int operator > (const int_double &lhs, const int_double &rhs);
  friend int operator < (const int_double &lhs, const int_double &rhs);
}; // end class

void print_int_double(const int_double &x)
{
  printf("[%20.18e,%20.18e]",x.left,x.right);
};

inline int_double operator + (const int_double &lhs, const int_double &rhs)
{
  int_double temp;
  temp.left=nextbefore(lhs.left+rhs.left);
  temp.right=nextafter(lhs.right+rhs.right);
  return(temp);
}

inline int_double operator += (int_double &lhs, const int_double &rhs)
{
  lhs=rhs+lhs;
  return lhs;
}

// unary minus
inline int_double operator - (const int_double &x)
{
  return int_double(-x.right,-x.left);
}

inline int_double operator - (const int_double &lhs, const int_double &rhs)
{
  int_double temp;
  temp.left=nextbefore(lhs.left-rhs.left);
  temp.right=nextafter(lhs.right-rhs.right);
  return(temp);
}

inline int_double operator * (const int_double &lhs, const int_double &rhs)
{
  double a=lhs.left*rhs.left;
  double b=lhs.left*rhs.right;
  double c=lhs.right*rhs.left;
  double d=lhs.right*rhs.right;
  double mx=max(a,b,c,d);
  double mn=min(a,b,c,d);
  return int_double(nextbefore(mn),nextafter(mx));
}  

bool contains_zero(const int_double &x)
{
  return (x.left<=0.0) && (x.right>=0.0);
}

inline int_double inv(const int_double &x)
{
  if(x.left<=0.0)
    {
      if(x.right>=0)
	return int_double(-nan(""),nan(""));
      else
	return int_double(nextbefore(1.0/x.right),nextafter(1.0/x.left));
    }
  return int_double(nextbefore(1.0/x.left),nextafter(1.0/x.right));
}

inline int_double operator / (const int_double &lhs, const int_double &rhs)
{
  if(contains_zero(rhs))
    return int_double(-nan(""),nan(""));
  double a=lhs.left/rhs.left;
  double b=lhs.left/rhs.right;
  double c=lhs.right/rhs.left;
  double d=lhs.right/rhs.right;
  double mx=max(a,b,c,d);
  double mn=min(a,b,c,d);
  return int_double(nextbefore(mn),nextafter(mx));
}

inline int_double log_two_sided(const int_double &x)
{
  return int_double(log_rd(x.left),log_ru(x.right));
}

inline int_double log(const int_double &x)
{
  if(x.left==x.right) // faster?
    {
      double rd=log_rd(x.left);
      return int_double(rd,nextafter(rd));
    }
  return log_two_sided(x);
}


#endif


