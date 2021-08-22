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

IMAGE img_hero,img_bighero;
IMAGE img_startmenu;

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
  load_map();//载入地图信息
  Hero.stair = 1;
  load_Monster();//载入monster信息

  initgraph(Width, High);
  setbkmode(TRANSPARENT);
  loadimage(&img_floor, _T("images\\floor.png"));
  loadimage(&img_wall, _T("images\\wall.png"));
  loadimage(&img_hero, _T("images\\Link.png"));
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
  BeginBatchDraw();
  while (gamestatus == 0) {
      start_menu();
  }
}

void start_menu() {
    drawAlpha(0, 0, &img_startmenu);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(30, 0, _T("黑体"));
    outtextxy(Width * 0.35, High * 6 / 8, _T("1 ENTER THE GAME"));
    outtextxy(Width * 0.35, High * 6.8 / 8, _T("2 QUIT"));
    FlushBatchDraw();
    Sleep(2);
    if (_kbhit()) {
        char input = _getch();
        if (input == '1') gamestatus = 1;
        else if (input == '2') {
            gamestatus = 2;
            exit(0);
        }
    }
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
  drawAlpha(Hero.position_x, Hero.position_y, &img_hero);

  Sleep(2);
  FlushBatchDraw();
}