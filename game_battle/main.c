#include<stdio.h>
#include<stdlib.h>
#include"function.h"

int main(void)
{
  static int c;
  static int m1, m2 = -2, l;
  static Monster *m;//monster
  static Technic *t;//technic

  //allocate memories & make monster, technic
  t = make_technic();
  m = make_monster(t);

  printf("select your monster: ");
  scanf("%d", &m1);

  while(1)
  {
    printf("select action(1(move), 2(level down), -1(end)): ");
    scanf("%d", &c);

    if(c == 1)
    {
      m2 = move();//move monster
      if(m2 != -2)
      {
        l = fight(t, m, m1, m2);//fight enemy
        //number of experience increase
        if(l == 0)
        {
          exp_up_win(m, m1, m2);
          level_up(m, m1);
        }
        else if(l == 1)
        {
          exp_up_lose(m, m1, m2);
          level_up(m, m1);
        }
        else if(l == -1)
        {
          //do nothing
          //escape!
        }
      }
    }
    else if(c == 2)
    {
      level_down(m, m1);
    }
    else if(c == -1)
    {
      printf("game over!\n");
      break;
    }
  }
  free(m);
  free(t);
  return 0;
}
