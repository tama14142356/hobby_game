#include<stdio.h>
#include"function.h"
void level_up(Monster *m, int num_monster)
{
  if(m[num_monster].level < 100 && m[num_monster].level >= 1)
  {
    if(m[num_monster].exp >= m[num_monster].exp_max)
    {
      printf("\nlevel up!\n");
      m[num_monster].exp -= m[num_monster].exp_max;
      ++m[num_monster].level;
      m[num_monster].exp_max += m[num_monster].level * 3 / 2;
      m[num_monster].attack_s += 2 * (m[num_monster].level % 3);
      m[num_monster].attack_p += 2 * ((m[num_monster].level + 1) % 3);
      m[num_monster].defense_s += 2 * ((m[num_monster].level + 1) % 3);
      m[num_monster].defense_p += 2 * (m[num_monster].level % 2);
      m[num_monster].hp += 5 * (m[num_monster].level % 3);
      printf("hp: +%d attack_s: +%d attack_p: +%d defense_s: +%d defense_p: +%d\n", 5 * (m[num_monster].level % 3), 2 * (m[num_monster].level % 3), 2 * ((m[num_monster].level + 1) % 3), 2 * ((m[num_monster].level + 1) % 3), 2 * (m[num_monster].level % 2));
    }
  } 
  else if(m[num_monster].level >= 100)
  {
    printf("congraturation! your monster is level max\n");
  }
}

void level_down(Monster *m, int num_monster)
{
  if(m[num_monster].level > 1)
  {
    printf("\nlevel down!!\n");
    m[num_monster].exp = 0;
    m[num_monster].exp_max -= m[num_monster].level * 3 / 2;
    m[num_monster].attack_s -= 2 * (m[num_monster].level % 3);
    m[num_monster].attack_p -= 2 * ((m[num_monster].level + 1) % 3);
    m[num_monster].defense_s -= 2 * ((m[num_monster].level + 1) % 3);
    m[num_monster].defense_p -= 2 * (m[num_monster].level % 2);
    m[num_monster].hp -= 5 * (m[num_monster].level % 3);
    printf("hp: -%d attack_s: -%d attack_p: -%d defense_s: -%d defense_p: -%d\n", 5 * (m[num_monster].level % 3), 2 * (m[num_monster].level % 3), 2 * ((m[num_monster].level + 1) % 3), 2 * ((m[num_monster].level + 1) % 3), 2 * (m[num_monster].level % 2));
    --m[num_monster].level;
  } 
  else if(m[num_monster].level <= 1)
  {
    printf("your monster is initial level\n");
    printf("can't level down\n");
  }
}

void exp_up_win(Monster *m, int m1, int m2)
{
  m[m1].exp += m[m2].level * 10;
}

void exp_up_lose(Monster *m, int m1, int m2)
{
  m[m1].exp += m[m2].level * 3 / 2;
}
