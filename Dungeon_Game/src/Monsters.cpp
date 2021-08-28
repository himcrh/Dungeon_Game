#include"Monsters.h"
#include"global.h"
BOSS boss_1 = {40 , 200 , 200};//≥ı ºªØboss_1

void vs_boss(BOSS cur_boss) {
  while (1) {
    draw_vs_boss();
    hero_move_boss();
  }
}
