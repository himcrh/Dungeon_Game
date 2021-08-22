#include "scene_draw.h"
void draw_backgraund(void) {
  //±³¾°»æÍ¼
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      drawAlpha(i*Unit,j*Unit, &img_floor);
    }
  }
}
void draw_nomonster(int x) {
    settextcolor(RED);
    settextstyle(30, 0, _T("Helvetica"));
    outtextxy(Width * 0.76, High * 0.1, _T("RUN,MY BOY!!!"));
}
void draw_monster(int x, Monster cur_M) {
    drawAlpha(Width * 0.56, High * 0.3,&img_monsters[x]);
    settextcolor(WHITE);
    settextstyle(30, 0, _T("Helvetica"));
    TCHAR s[10];
    outtextxy(Width * 0.76, High * 0.2, _T("HP:"));
    _stprintf_s(s, _T("%d"), cur_M.HP);
    if (cur_M.HP < 100) settextcolor(RED);
    outtextxy(Width * 0.82, High * 0.2, s);
    settextcolor(WHITE);
    outtextxy(Width * 0.76, High * 0.3, _T("ATK:"));
    _stprintf_s(s, _T("%d"), cur_M.attack);
    outtextxy(Width * 0.84, High * 0.3, s);
    outtextxy(Width * 0.76, High * 0.4, _T("EXP:"));
    _stprintf_s(s, _T("%d"), cur_M.EXP);
    outtextxy(Width * 0.84, High * 0.4, s);
}
void draw_information(void) {
    for (int i = 11; i <= 21; i++) {
        for (int j = 0; j <= 10; j++) {
            drawAlpha(i * Unit, j * Unit, &img_floor);
        }
    }
    setcolor(WHITE);
    rectangle(440, 0, 880, 220);
    rectangle(440, 220, 880, 440);
    settextcolor(WHITE);
    settextstyle(30, 0, _T("Helvetica"));
    TCHAR s[10];
    outtextxy(Width * 0.52, High * 0.52, _T("HP:"));
    outtextxy(Width * 0.52, High * 0.62, _T("ATK:"));
    outtextxy(Width * 0.52, High * 0.72, _T("EXP:"));
    outtextxy(Width * 0.52, High * 0.82, _T("MONEY:"));
    settextcolor(GREEN);
    if (Hero.HP < 300) settextcolor(RED);
    _stprintf_s(s, _T("%d"), Hero.HP);
    outtextxy(Width * 0.58, High * 0.52, s);
    settextcolor(GREEN);
    _stprintf_s(s, _T("%d"), Hero.attack);
    outtextxy(Width * 0.6, High * 0.62, s);
    _stprintf_s(s, _T("%d"), Hero.EXP);
    outtextxy(Width * 0.6, High * 0.72, s);
    _stprintf_s(s, _T("%d"), Hero.money);
    outtextxy(Width * 0.64, High * 0.82, s);
    settextcolor(BLUE);
    outtextxy(Width * 0.52, High * 0.92, _T("Welcome to the wonderland!"));
    outtextxy(Width * 0.89, High * 0.53, _T("Lv: "));
    _stprintf_s(s, _T("%d"), Hero.Level);
    outtextxy(Width * 0.93, High * 0.53, s);
    drawAlpha(Width * 0.8, High * 0.58, &img_bighero);
}

void draw_fixobject(void) {
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      if (map[Hero.stair][i][j] == 1)
        drawAlpha(i*Unit, j*Unit, &img_wall);
      if (map[Hero.stair][i][j] == 2)
        drawAlpha(i * Unit, j * Unit, &img_circle_down);
      if (map[Hero.stair][i][j] == 3)
        drawAlpha(i * Unit, j * Unit, &img_circle_up);
    }
  }
}

void draw_unfixobject(void) {
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      if (map[Hero.stair][i][j] > 10 && map[Hero.stair][i][j] <= 90)
        drawAlpha(i * Unit, j * Unit, &img_monsters[map[Hero.stair][i][j]-10]);
    }
  }
}

void load_map(void) {
  fstream Map_file;
  Map_file.open("Map_file.txt", ios::in);
  if (!Map_file)
    return;
  freopen("Map_file.txt", "r", stdin);
  int n;
  scanf_s("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 10; j++) {
      for (int k = 0; k <= 10; k++) {
        scanf_s("%d", &map[i][k][j]);
      }
    }
  }
  fclose(stdin);
  freopen("CON", "r", stdin);
}

void start_menu() {
  drawAlpha(0, 0, &img_startmenu);
  setbkmode(TRANSPARENT);
  settextcolor(BLACK);
  settextstyle(30, 0, _T("ºÚÌå"));
  outtextxy(Width * 0.35, High * 6 / 8, _T("1 ENTER THE GAME"));
  outtextxy(Width * 0.35, High * 6.8 / 8, _T("2 QUIT"));
  FlushBatchDraw();
  Sleep(2);
  if (_kbhit()) {
    char input = _getch();
    if (input == '1')
      gamestatus = 1;
    else if (input == '2') {
      gamestatus = 2;
      exit(0);
    }
  }
}