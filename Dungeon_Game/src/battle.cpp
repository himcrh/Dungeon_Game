#include"battle.h"
//判断能否打过
bool vs_cmp(int cur_monster,int x,int y) {
  if (cur_monster > 90 || cur_monster <= 10)//不是怪物
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
  if (cnt_a <= cnt_b) {//能打过
    battle_details(cur_monster,x,y);
    return true;
  }
  
  show_monster.second = Monsters[cur_monster];//打不过
  show_monster.first = true;//判断是否打得过
  return false;
}
//能打过，显示交战细节
void battle_details(int cur_monster,int x,int y) {
  Monster cur_M = Monsters[cur_monster];
  //提取出一个moster
  while (cur_M.HP > 0) {
    cur_M.HP -= Hero.attack;
    if (cur_M.HP > 0)
      Hero.HP -= cur_M.attack;
    draw_backgraund();
    draw_information();
    draw_monster(cur_M);
    draw_fixobject();
    draw_unfixobject();
    drawAlpha(Hero.position_x, Hero.position_y, &img_hero[Hero.dir]);
    FlushBatchDraw();
    Sleep(200);
  }
  map[Hero.stair][x][y] = 0;
  Hero.EXP += cur_M.EXP;
  if (Hero.EXP > 100) {
      Hero.EXP -= 100;
      Hero.Level++;
      Hero.attack += 10;
  }
  Hero.money += cur_M.money;
}


