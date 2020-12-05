typedef struct
{
  int pp;//number tevhnic can use
  int attack_s, attack_p;//attack power(special,physical)
  int attack_d_s, attack_u_s, attack_d_p, attack_u_p;//decrerase or increase attack power(special,physical)
  int defense_d_s, defense_u_s, defense_d_p, defense_u_p;//decrerase or increase defense power(special,physical)
  int prob;//percentage technic do
  int number;//technic number
}Technic;

typedef struct
{
  int level;// level of monster
  int hp;//hit points
  int attack_s, attack_p;//attack power(special, physical)
  int defense_s, defense_p;//defense power(special,physical)
  int exp;//experience points
  int exp_max;//max experience points
  Technic t[4];//technic points
}Monster;

int rand_range(int a, int b);
void level_up(Monster *m, int num_monster);
void level_down(Monster *m, int num_monster);
int fight(Technic *t, Monster *m, int m1, int m2);//m1: your monster's number, m2: other monster's number
void exp_up_win(Monster *m, int m1, int m2);//m1: your monster's number, m2: other monster's number
void exp_up_lose(Monster *m, int m1, int m2);//m1: your monster's number, m2: other monster's number
int move(void);//move monster
Monster *make_monster(Technic *t);
Technic *make_technic(void);
