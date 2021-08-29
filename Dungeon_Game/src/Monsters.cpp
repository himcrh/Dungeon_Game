#include"Monsters.h"
#include"global.h"
BOSS boss_1 = {40 , 200 , 200};//≥ı ºªØboss_1

void vs_boss(BOSS cur_boss) {
  while (1) {
    draw_vs_boss();
    hero_move_boss();
    move_swordair();
    Sleep(2);
  }
}

void move_swordair(void) {
  for (int i = 0; i < swordairs.size(); i++) {
    switch (swordairs[i].dir) { 
      case 1:
        swordairs[i].y -= 5;
        break;
      case 2:
        swordairs[i].y += 5;
        break;
      case 3:
        swordairs[i].x -= 5;
        break;
      case 4:
        swordairs[i].x += 5;
        break;
    }
    if (swordairs[i].x > 440 || swordairs[i].x < 0 || swordairs[i].y > 440 ||
        swordairs[i].y < 0) {
      swordairs.erase(swordairs.begin() +i);
    }
  }
}
