#include "scene_draw.h"

void draw_backgraund(void) {
  //±³¾°»æÍ¼
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      drawAlpha(i*Unit,j*Unit, &img_floor);
    }
  }
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
    outtextxy(Width * 0.52, High * 0.62, _T("ATTACK:"));
    outtextxy(Width * 0.52, High * 0.72, _T("EXP:"));
    outtextxy(Width * 0.52, High * 0.82, _T("MONEY:"));
    settextcolor(GREEN);
    _stprintf_s(s, _T("%d"), Hero.HP);
    outtextxy(Width * 0.58, High * 0.52, s);
    _stprintf_s(s, _T("%d"), Hero.attack);
    outtextxy(Width * 0.65, High * 0.62, s);
    _stprintf_s(s, _T("%d"), Hero.EXP);
    outtextxy(Width * 0.6, High * 0.72, s);
    _stprintf_s(s, _T("%d"), Hero.money);
    outtextxy(Width * 0.64, High * 0.82, s);

    settextcolor(BLUE);
    outtextxy(Width * 0.52, High * 0.9, _T("Welcome to the wonderland!"));
    drawAlpha(Width * 0.82, High * 0.52, &img_bighero);
}

void draw_fixobject(void) {
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      if (map[Hero.stair][i][j] == 1)
        drawAlpha(i*Unit, j*Unit, &img_wall);
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