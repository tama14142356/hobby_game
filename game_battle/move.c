#include<stdio.h>
#include"function.h"
int move(void)
{
  int n;
  while(1)
  {
    printf("select direrction(1, 2, 3, 4)");
    scanf("%d", &n);
    if(n == 1)
    {
      if(rand_range(0, 100) <= 50)
      {
        printf("\nenemy appear!!\n");
        return rand_range(0, 1000);
      }
      else
      {
        continue;
      }
    }
    else if(n == 2)
    {
      if(rand_range(0, 100) <= 40)
      {
        printf("\nenemy appear!!\n");
        return rand_range(0, 1000);
      }
      else
      {
        continue;
      }
    }
    else if(n == 3)
    {
      if(rand_range(0, 100) <= 60)
      {
        printf("\nenemy appear!!\n");
        return rand_range(0, 1000);
      }
      else
      {
        continue;
      }
    }
    else if(n == 4)
    {
      if(rand_range(0, 100) <= 70)
      {
        printf("\nenemy appear!!\n");
        return rand_range(0, 1000);
      }
      else
      {
        continue;
      }
    }
    else
    {
      printf("can't move \n");
      continue; 
    }
  }
}
