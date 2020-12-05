#include"quake.h"
#include<stdlib.h>
#include<time.h>

double rand_range(double a, double b)
{
  double s;

  s = ((double)rand() / ((double)RAND_MAX + 1) * (b - a + 1));
  s += a;

  return s;
}

Quake *make_quake(void)
{
  Quake *q;
  srand((unsigned)time(0));

  q.mag = rand_range(0.0, 50.0);
  if(q.mag == 0)
  {
    q.deg = 0.0;
    q.depth_center = -1.0;
    q.dis_center = -1.0;
    q.p.x = -1.0;
    q.p.y = -1.0
  }
  else
  {
    q.deg = rand_range(1.0, 10.0);
    q.depth_center = rand_range(1.0, (double)RAND_MAX);
    q.dis_center = rand_range(1.0, (double)RAND_MAX);
    q.p.x = rand_range(0.0, (double)RAND_MAX);
    q.p.y = rand_range(0.0, (double)RAND_MAX);
  }

  return q;
}
