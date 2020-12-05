#include<stdlib.h>
#include"function.h"

static int num = 1000;

Monster *make_monster(Technic *t)
{
  int i, j;

//allocate memory
  Monster *m = (Monster *)malloc(sizeof(Monster) * num);
  if(m == NULL)
  {
    return NULL;
  }

  for(i = 0; i < num; ++i)
  {
    m[i].hp = rand_range(50, 1000);
    m[i].exp = 0;
    m[i].level = rand_range(6, 50);
    m[i].exp_max = rand_range(6, 150);
    m[i].defense_s = rand_range(30, 300);
    m[i].defense_p = rand_range(30, 300);
    m[i].attack_p = rand_range(50, 300);
    m[i].attack_s = rand_range(50, 300);
  }
  for(i = 0; i < num; ++i)
  {
    int n;
    n = sizeof(m[i].t) / sizeof(Technic);
    for(j = 0; j < n; ++j)
    {
      int l = rand_range(0, 1000);
      m[i].t[j] = t[l];
    }
  }

  return m;
}

Technic *make_technic(void)
{
  int i;

  Technic *t = (Technic *)malloc(sizeof(Technic) * num);
  if(t == NULL)
  {
    return NULL;
  }
  
  for(i = 0; i < num; ++i)
  {
    t[i].number = i;
    t[i].pp = rand_range(3, 30);
    t[i].prob = rand_range(5, 100);
    t[i].attack_d_p = rand_range(0, 6);
    t[i].attack_u_p = rand_range(0, 6);
    t[i].attack_d_s = rand_range(0, 6);
    t[i].attack_u_s = rand_range(0, 6);
    t[i].defense_d_p = rand_range(0, 6);
    t[i].defense_u_p = rand_range(0, 6);
    t[i].defense_d_s = rand_range(0, 6);
    t[i].defense_u_s = rand_range(0, 6);
    if(i <= num / 2)
    {
      t[i].attack_p = rand_range(0, 200);
      if(t[i].attack_p <= 50)
      {
        t[i].attack_p = 0;
        t[i].attack_s = rand_range(50, 200);
      }
    }
    else
    {
      t[i].attack_s = rand_range(0, 200);
      if(t[i].attack_s <= 50)
      {
        t[i].attack_s = 0;
        t[i].attack_p = rand_range(50, 200);
      }
    }
  }
  
  return t;
}
