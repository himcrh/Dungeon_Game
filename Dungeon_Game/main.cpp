#include"src/global.h"
#pragma comment(lib, "winmm.lib")

int map[10][13][13];
int gamestatus;
IMAGE img_background;
IMAGE img_test;
IMAGE img_floor;
IMAGE img_wall;
IMAGE img_monsters[7];
IMAGE img_heart,img_peach;
IMAGE img_cloud[5];
IMAGE img_hero[5],img_bighero;
IMAGE img_startmenu;
IMAGE img_magiccircle;
void start_initial(void);  //初始化，加载文件
void start_menu(void);
void show(void);
HERO Hero;
Monster Monsters[7];


int main() {
  start_initial();
  while (gamestatus) {
    show();
  }
  return 0;
}

void start_initial() {
  srand(time(NULL));//随机时间种子
  hero_initial();//英雄初始化
  load_map();//载入地图信息
  load_Monster();//载入monster信息

  initgraph(Width, High);
  setbkmode(TRANSPARENT);
  loadimage(&img_floor, _T("images\\floor.png"));
  loadimage(&img_wall, _T("images\\wall.png"));
  loadimage(&img_hero[1], _T("images\\Link_U.png"));
  loadimage(&img_hero[2], _T("images\\Link_D.png"));
  loadimage(&img_hero[3], _T("images\\Link_L.png"));
  loadimage(&img_hero[4], _T("images\\Link_R.png"));
  loadimage(&img_monsters[1], _T("images\\monster_1.png"));
  loadimage(&img_monsters[2], _T("images\\monster_2.png"));
  loadimage(&img_monsters[3], _T("images\\monster_3.png"));
  loadimage(&img_monsters[4], _T("images\\monster_4.png"));
  loadimage(&img_monsters[5], _T("images\\monster_5.png"));
  loadimage(&img_heart, _T("images\\heart.png"));
  loadimage(&img_peach, _T("images\\peach.png"));
  loadimage(&img_cloud[1], _T("images\\cloud_1.png"));
  loadimage(&img_cloud[2], _T("images\\cloud_2.png"));
  loadimage(&img_cloud[3], _T("images\\cloud_3.png"));
  loadimage(&img_startmenu, _T("images\\startmenu.png"));
  loadimage(&img_bighero, _T("images\\BigLink.png"));
  loadimage(&img_magiccircle, _T("images\\magiccircle.png"));
  BeginBatchDraw();
  while (gamestatus == 0)  start_menu();
}


void gameover() {
    EndBatchDraw();
    closegraph();
}

void show() {
  draw_backgraund();
  draw_information();
  draw_fixobject();
  draw_unfixobject();
  hero_move();
  drawAlpha(Hero.position_x, Hero.position_y, &img_hero[Hero.dir]);
  Sleep(2);
  FlushBatchDraw();
}