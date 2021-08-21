#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
#include"src/easy_draw.h"
#pragma comment(lib, "winmm.lib")

#define High 440
#define Width 880
#define Unit 40
using namespace std;

IMAGE img_background;
IMAGE img_test;
IMAGE img_floor;
IMAGE img_wall;
int map[13][13];

void test(void); //������
void start_initial(void);  //��ʼ���������ļ�
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
  srand(time(NULL));//���ʱ������

  //�����ͼ��Ϣ
  fstream Map_file.open("Map_file.txt", ios::in);


  initgraph(Width, High);
  setbkmode(TRANSPARENT);
  loadimage(&img_test, _T("images\\test.png"));
  loadimage(&img_floor, _T("images\\floor.png"));
  loadimage(&img_wall, _T("images\\wall.png"));
  BeginBatchDraw();
}

void test() {
  drawAlpha(0, 0,&img_test);
  FlushBatchDraw();
  Sleep(5000000);
}

void show() {

  //������ͼ
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      drawAlpha(i * 40, j * 40, &img_floor);
      //������ΧһȦǽ��
      if (i == 0 || i == 10 || j == 0 || j == 10) {
        drawAlpha(i * 40, j * 40, &img_wall);
      }
         
    }
  }


  Sleep(2);
  FlushBatchDraw();
}