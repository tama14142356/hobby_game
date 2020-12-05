#include"quake.h"

double root(double a)
{
  double x =  a / 2;
  double last_x = 0.0;

  while(x != last_x)
  {
    last_x = x;
    x = (x + a / x) / 2.0;
  }
  return x;
}


double measure(Quake *q, double x, double y)
{
  double ans;

  ans = ((q.point.x - x) * (q.point.x - x)) + ((q.point.y - y) * (q.point.y - y));
  
  ans = root(ans);
  return ans;
}
