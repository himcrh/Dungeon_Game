#include "scene_draw.h"

void draw_backgraund(void) {
  //±³¾°»æÍ¼
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      drawAlpha(i*Unit,j*Unit, &img_floor);
    }
  }

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