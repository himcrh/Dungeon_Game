#include "hero.h"
#include"global.h"

bool is_Forbidden(int x, int y) {

  if (x < 0 || y < 0 || x>400 || y>400) return 0;
  //dir up - 1; down - 2; left - 3; right - 4;
  int dx = x / 40;
  int dy = y / 40;
  
  if (x % 40 == 0 && y % 40 == 0) return 1;
  if (x % 40 == 0) {
    if (map[Hero.stair][dx][dy] != 1 && map[Hero.stair][dx][dy + 1] != 1) {
      //这两个不是墙
      if (vs_cmp(map[Hero.stair][dx][dy],dx,dy) &&
          vs_cmp(map[Hero.stair][dx][dy + 1], dx, dy+1)) {
        return 1;
      }
    }
      
  }
  if (y % 40 == 0) {
    if (map[Hero.stair][dx][dy] != 1 && map[Hero.stair][dx + 1][dy] != 1) {
      if (vs_cmp(map[Hero.stair][dx][dy], dx, dy) &&
          vs_cmp(map[Hero.stair][dx + 1][dy], dx+1, dy)) {
        return 1;
      }
    }
  }
  if (map[Hero.stair][dx][dy] ==0 && map[Hero.stair][dx][dy + 1] == 0 &&
      map[Hero.stair][dx + 1][dy] ==0 &&
      map[Hero.stair][dx + 1][dy + 1] ==0) {
    return 1;
  }
  return 0;
}

void hero_initial(void) {
  Hero.HP = 500;
  Hero.attack = 50;
  Hero.stair = 1;
  Hero.Level = 1;
  Hero.dir = 4;
}

void hero_move() {
  if (_kbhit()) {
      switch (_getch()) {
          //up
        case 72:
          Hero.dir = 1;
          if (is_Forbidden(Hero.position_x, Hero.position_y - 10))
              Hero.position_y -= 10;
          break;
          //down
        case 80:
          Hero.dir = 2;
          if (is_Forbidden(Hero.position_x, Hero.position_y + 10))
              Hero.position_y += 10;
          break;
          //left
        case 75:
          Hero.dir = 3;
          if (is_Forbidden(Hero.position_x - 10, Hero.position_y))
              Hero.position_x -= 10;
          break;
          //right
        case 77:
          Hero.dir = 4;
          if (is_Forbidden(Hero.position_x + 10, Hero.position_y))
              Hero.position_x += 10;
          break;
      }
  }

}