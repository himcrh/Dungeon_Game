#include"battle.h"

bool vs_cmp(int cur_monster,int x,int y) {
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
  if (cnt_a <= cnt_b) {
    battle_details(cur_monster,x,y);
    return true;
  }
    
  return false;
}

void battle_details(int cur_monster,int x,int y) {
  Monster cur_M = Monsters[cur_monster];
  //提取出一个moster
  while (cur_M.HP > 0) {
    cur_M.HP -= Hero.attack;
    Hero.HP -= cur_M.attack;
    draw_backgraund();
    draw_information();
    draw_fixobject();
    draw_unfixobject();
    drawAlpha(Hero.position_x, Hero.position_y, &img_hero[Hero.dir]);
    FlushBatchDraw();
    Sleep(200);
  }
  map[Hero.stair][x][y] = 0;
  Hero.EXP += cur_M.EXP;
  Hero.money += cur_M.money;
}


