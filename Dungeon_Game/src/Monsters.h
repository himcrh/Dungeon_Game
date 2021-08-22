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
void load_Monster(void);
#endif  // !MONSTERS
