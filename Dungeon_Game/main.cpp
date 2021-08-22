#include"src/global.h"
#pragma comment(lib, "winmm.lib")

int map[10][13][13];
IMAGE img_test;
IMAGE img_floor;
IMAGE img_wall;
IMAGE img_monsters[7];
IMAGE img_hero;

void test(void); //测试用
void start_initial(void);  //初始化，加载文件
void show(void);
HERO Hero;
Monster Monsters[7];


int main() {
  start_initial();
  //test();
  while (true) {
    show();
  }
  return 0;
}

void start_initial() {
  srand(time(NULL));//随机时间种子
  load_map();//载入地图信息
  Hero.stair = 1;
  load_Monster();//载入monster信息

  initgraph(Width, High);
  setbkmode(TRANSPARENT);
  loadimage(&img_floor, _T("images\\floor.png"));
  loadimage(&img_wall, _T("images\\wall.png"));
  loadimage(&img_hero, _T("images\\monster_1.png"));
  loadimage(&img_monsters[1], _T("images\\monster_1.png"));
  loadimage(&img_monsters[2], _T("images\\monster_2.png"));
  loadimage(&img_monsters[3], _T("images\\monster_3.png"));
  loadimage(&img_monsters[4], _T("images\\monster_4.png"));
  loadimage(&img_monsters[5], _T("images\\monster_5.png"));
  BeginBatchDraw();
}

void test() {
  drawAlpha(0, 0,&img_test);
  FlushBatchDraw();
  Sleep(5000000);
}

void gameover() {
    EndBatchDraw();
    closegraph();
}

void show() {

  draw_backgraund();
  draw_fixobject();
  draw_unfixobject();
  hero_move();
  drawAlpha(Hero.position_x, Hero.position_y, &img_hero);
  Sleep(2);
  FlushBatchDraw();

}