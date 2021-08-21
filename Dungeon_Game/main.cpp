#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include"src/easy_draw.h"
#pragma comment(lib, "winmm.lib")
using namespace std;
#define High 440
#define Width 880
#define Unit 40
int map[10][13][13];

IMAGE img_background;
IMAGE img_test;
IMAGE img_floor;
IMAGE img_wall;
IMAGE img_monster_1, img_monster_2, img_monster_3, img_monster_4, img_monster_5;
void test(void); //测试用
void start_initial(void);  //初始化，加载文件
void show(void);

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

  //载入地图信息
  fstream Map_file;
  Map_file.open("Map_file.txt",ios::in);
  if (!Map_file) return;
  freopen("Map_file.txt", "r", stdin);
  int n; scanf_s("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 10; j++) {
      for (int k = 0; k <= 10; k++) {
        scanf_s("%d", &map[i][j][k]);
      }
    }
  }
  
  initgraph(Width, High);
  setbkmode(TRANSPARENT);
  loadimage(&img_floor, _T("images\\floor.png"));
  loadimage(&img_wall, _T("images\\wall.png"));
  loadimage(&img_monster_1, _T("images\\monster_1.png"));
  loadimage(&img_monster_2, _T("images\\monster_2.png"));
  loadimage(&img_monster_3, _T("images\\monster_3.png"));
  loadimage(&img_monster_4, _T("images\\monster_4.png"));
  loadimage(&img_monster_5, _T("images\\monster_5.png"));
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

  //背景绘图
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      switch (map[1][i][j]) {
        case 0:
          drawAlpha(j * 40, i * 40, &img_floor);
          break;
        case 1:
          drawAlpha(j * 40, i * 40, &img_wall);
          break;
        case 2:
          drawAlpha(j * 40, i * 40, &img_wall);
          break;
        case 3:
          drawAlpha(j * 40, i * 40, &img_wall);
          break;
        case 4:
          drawAlpha(j * 40, i * 40, &img_wall);
          break;
        case 5:
          drawAlpha(j * 40, i * 40, &img_wall);
          break;
      }
    }
  }


  Sleep(2);
  FlushBatchDraw();

}