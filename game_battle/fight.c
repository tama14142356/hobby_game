#include<stdio.h>
#include"function.h"

int fight(Technic *t, Monster *m, int m1, int m2)
{
  int turn = 1;//attack turn
  int n1, n;

  printf("monster %d appered!\n", m2);
  Monster l1 = m[m1], l2 = m[m2];

  printf("your moster: hp:%d t1: attack_s: %d attack_p: %d prob: %d pp: %d t2: attack_s: %d attack_p: %d prob: %d pp: %d t3: attack_s: %d attack_p: %d prob: %d pp: %d t4: attack_s: %d attack_p: %d prob: %d pp: %d\n", m[m1].hp, m[m1].t[0].attack_s, m[m1].t[0].attack_p, m[m1].t[0].prob, m[m1].t[0].pp, m[m1].t[1].attack_s, m[m1].t[1].attack_p, m[m1].t[1].prob, m[m1].t[1].pp, m[m1].t[2].attack_s, m[m1].t[2].attack_p, m[m1].t[2].prob, m[m1].t[2].pp, m[m1].t[3].attack_s, m[m1].t[3].attack_p, m[m1].t[3].prob, m[m1].t[3].pp);
  printf("enemy moster: hp:%d t1: attack_s: %d attack_p: %d prob: %d pp: %d t2: attack_s: %d attack_p: %d prob: %d pp: %d t3: attack_s: %d attack_p: %d prob: %d pp: %d t4: attack_s: %d attack_p: %d prob: %d pp: %d\n", m[m2].hp, m[m2].t[0].attack_s, m[m2].t[0].attack_p, m[m2].t[0].prob, m[m2].t[0].pp, m[m2].t[1].attack_s, m[m2].t[1].attack_p, m[m2].t[1].prob, m[m2].t[1].pp, m[m2].t[2].attack_s, m[m2].t[2].attack_p, m[m2].t[2].prob, m[m2].t[2].pp, m[m2].t[3].attack_s, m[m2].t[3].attack_p, m[m2].t[3].prob, m[m2].t[3].pp);

  while(1)
  {
    if(turn == 1)
    {
      printf("Turn you:\n");
      printf("fight or escape?(1 or 2): ");
      scanf("%d", &n1);
      if(n1 == 1)
      {
        printf("Input attack number(1, 2, 3, 4): ");
        scanf("%d", &n);
        if(n == 1 || n == 2 || n == 3 || n == 4)
        {
          if(m[m1].t[n].pp >= 1)
          {
            if(rand_range(0, 100) <= m[m1].t[n].prob)
            {
              printf("\nattack success!\n");
              m[m2].hp -= m[m1].attack_p * m[m1].t[n].attack_p / m[m2].defense_p;
              m[m2].hp -= m[m1].attack_s * m[m1].t[n].attack_s / m[m2].defense_s;
              m[m2].attack_p -= m[m1].t[n].attack_d_p;
              m[m2].attack_s -= m[m1].t[n].attack_d_s;
              m[m2].attack_p += m[m1].t[n].attack_u_p;
              m[m2].attack_s += m[m1].t[n].attack_u_s;
              if(rand_range(0, 100) <= 20)
              {
                printf("\nexcellent attack!\n");
                m[m2].hp += m[m1].attack_p * m[m1].t[n].attack_p / m[m2].defense_p;
                m[m2].hp += m[m1].attack_s * m[m1].t[n].attack_s / m[m2].defense_s;

                m[m2].hp -= m[m1].attack_p * m[m1].t[n].attack_p / m[m2].defense_p * 3 / 2;
                m[m2].hp -= m[m1].attack_s * m[m1].t[n].attack_s / m[m2].defense_s * 3 / 2;
              }
            }
            else
            {
              printf("\nmiss!\n");
            }
            --m[m1].t[n].pp;
          }
          else
          {
            if(m[m1].t[0].pp < 1 && m[m1].t[1].pp < 1 && m[m1].t[2].pp < 1 && m[m1].t[3].pp < 1)
            {
              printf("all technic points is nothing\nevil attack\n");
              m[m2].hp -= 10 + 500 / m[m2].defense_p;
              m[m1].hp -= 100 + 1000 / m[m1].defense_p;
            }
            else
            {
              printf("pp is empty\n");
              continue;
            }
          }
        }
        else
        {
          printf("can't use it!\n");
          continue;
        }
      }
      else if(n1 == 2)
      {
        if(rand_range(0, 100) <= 60)
        {
          printf("escape success!\n");
          m[m1] = l1;//recover monster life
          m[m2] = l2;
          return -1;
        }
        else
        {
          printf("escape false!\n");
          turn = 3 - turn;
        }
      }
      printf("your monster: hp:%d enemy: hp:%d\n", m[m1].hp, m[m2].hp);
    }
    else
    {
      printf("Turn enemy:\n");
     /* printf("Input attack number(1, 2, 3, 4): ");
      scanf("%d", &n);*/
      n = rand_range(1, 4);

      if(n == 1 || n == 2 || n == 3 || n == 4)
      {
        if(m[m2].t[n].pp >= 1)
        {
          if(rand_range(0, 100) <= m[m2].t[n].prob)
          {
            printf("\nattack success!\n");
            m[m1].hp -= m[m2].attack_p * m[m2].t[n].attack_p / m[m1].defense_p;
            m[m1].hp -= m[m2].attack_s * m[m2].t[n].attack_s / m[m1].defense_s;
            m[m1].attack_p -= m[m2].t[n].attack_d_p;
            m[m1].attack_s -= m[m2].t[n].attack_d_s;
            m[m1].attack_p += m[m2].t[n].attack_u_p;
            m[m1].attack_s += m[m2].t[n].attack_u_s;
            if(rand_range(0, 100) <= 20)
            {
              printf("\nexcellent attack!\n");
              m[m1].hp += m[m2].attack_p * m[m2].t[n].attack_p / m[m1].defense_p;
              m[m1].hp += m[m2].attack_s * m[m2].t[n].attack_s / m[m1].defense_s;

              m[m1].hp -= m[m2].attack_p * m[m2].t[n].attack_p / m[m1].defense_p * 3 / 2;
              m[m1].hp -= m[m2].attack_s * m[m2].t[n].attack_s / m[m1].defense_s * 3 / 2;
            }
          }
          else
          {
            printf("\nmiss!\n");
          }
          --m[m2].t[n].pp;
        }
        else
        {
          if(m[m2].t[0].pp < 1 && m[m2].t[1].pp < 1 && m[m2].t[2].pp < 1 && m[m2].t[3].pp < 1)
          {
            printf("all technic points is nothing\nevil attack\n");
            m[m1].hp -= 10 + 500 / m[m1].defense_p;
            m[m2].hp -= 100 + 1000 / m[m2].defense_p;
          }
          else
          {
            printf("pp is empty\n");
            continue;
          }
        }
      }
      else
      {
        printf("can't use it!\n");
        continue;
      }
      printf("your monster: hp:%d enemy: hp:%d\n", m[m1].hp, m[m2].hp);
    }
    turn = 3 - turn;

    if(m[m2].hp <= 0)
    {
      printf("\nwin!\n");
      m[m1] = l1;//recover monster life
      m[m2] = l2;
      return 0;
    }
    if(m[m1].hp <= 0)
    {
      printf("\nlose!\n");
      m[m1] = l1;//recover monster life
      m[m2] = l2;
      return 1;
    }
  }
}
