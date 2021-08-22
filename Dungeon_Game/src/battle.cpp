#include"battle.h"

bool vs_cmp(int cur_monster) {
  if (cur_monster > 90 || cur_monster <= 10)
    return true;
  cur_monster -= 10;
  int cnt_a; 
  cnt_a = Monsters[cur_monster].HP / Hero.attack;
  if (Monsters[cur_monster].HP % Hero.attack)
    cnt_a++;
  
  int cnt_b;
  cnt_b = Hero.HP / Monsters[cur_monster].attack;
  if (Hero.HP % Monsters[cur_monster].attack)
    cnt_b++;
  if (cnt_a <= cnt_b)
    return true;
  return false;
}
