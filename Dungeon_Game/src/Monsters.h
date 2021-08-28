#ifndef MONSTERS
#define MONSTERS
#include<graphics.h>
#include<conio.h>
struct Monster {
  int id;
  int HP;
  int attack;
  int money;
  int EXP;
};
struct BOSS {
  int HP;
  int x;
  int y;
};
void vs_boss(BOSS cur_boss);
#endif  // !MONSTERS
