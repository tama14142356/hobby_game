#include<stdlib.h>
//random integer number in (a,b)
int rand_range(int a, int b)
{
  int s;
  
  if(a < b)
  {
    s = rand() / (RAND_MAX / (b - a + 1) + 1);
    s += a;
  }
  else if(b == a)
  {
    return a;
  }
  else
  {
    s = rand() / (RAND_MAX / (a - b + 1) + 1);
    s += b;
  }
  return s;
}
