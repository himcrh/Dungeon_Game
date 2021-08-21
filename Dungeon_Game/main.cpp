#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
#include"src/easy_draw.h"
#pragma comment(lib, "winmm.lib")

#define High 600
#define Width 600
using namespace std;

IMAGE img_background;
IMAGE img_test;

void test(void); //测试用
void start_initial(void);  //初始化，加载文件
void gameover(void);//测试上传
int main() {
  start_initial();
  test();
  gameover();
  return 0;
}

void start_initial() {
  srand(time(NULL));//随机时间种子
  initgraph(Width, High);
  setbkmode(TRANSPARENT);
  loadimage(&img_background, _T("images\\bg2.png"));
  loadimage(&img_test, _T("images\\test.png"));
  BeginBatchDraw();
}
void test() {
  putimage(0, 0, &img_background);
  drawAlpha(&img_test,0, 0);
  FlushBatchDraw();
  Sleep(5000000);
}
void gameover() {
	EndBatchDraw();
	closegraph();

}