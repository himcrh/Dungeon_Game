#include"info_load.h"
#include"global.h"

void save_info(void) {
  freopen("data.txt", "w", stdout);
  printf("%d %d %d %d %d %d %d %d %d %d %d\n", Hero.HP, Hero.attack, Hero.stair,
         Hero.Level, Hero.dir, Hero.sword, Hero.item_yellow, Hero.item_blue,
         Hero.item_red,Hero.position_x,Hero.position_y);//存档英雄信息
  printf("%d\n", cnt_map);//地图层数
  for (int i = 1; i <= cnt_map; i++) {
    for (int j = 0; j <= 10; j++) {
      for (int k = 0; k <= 10; k++) {
        printf("%d ", map[i][k][j]);
      }
      puts("");
    }
  }
  fclose(stdout);
  freopen("CON", "w", stdout);
}

bool read_info(void) {
  // return 0 读档失败;   return 1 正常
  fstream data_file;
  data_file.open("data.txt", ios::in);
  if (!data_file)
    return 0;
  freopen("data.txt", "r", stdin);
  scanf_s("%d %d %d %d %d %d %d %d %d %d %d",&Hero.HP,&Hero.attack,&Hero.stair,
         &Hero.Level,&Hero.dir,&Hero.sword, &Hero.item_yellow, &Hero.item_blue,
         &Hero.item_red,&Hero.position_x,&Hero.position_y);  //读档英雄信息
  scanf_s("%d", &cnt_map);
  int n = cnt_map;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 10; j++) {
      for (int k = 0; k <= 10; k++) {
        scanf_s("%d", &map[i][k][j]);
      }
    }
  }
  fclose(stdin);
  freopen("CON", "r", stdin);
  return 1;
}
