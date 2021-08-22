#include "hero.h"
#include"global.h"

bool is_Forbidden(int x, int y) {
  int dx = x / 40;
  int dy = y / 40;
  if (x < 0 || y < 0 || x>400 || y>400) return 0;
  if (x % 40 == 0 && y % 40 == 0) return 1;
  if (x % 40 == 0) {
    if (map[Hero.stair][dx][dy] != 1 && map[Hero.stair][dx][dy + 1] != 1)
      return 1;
  }
  if (y % 40 == 0) {
    if (map[Hero.stair][dx][dy] != 1 && map[Hero.stair][dx+1][dy] != 1)
      return 1;
  }
  if (map[Hero.stair][dx][dy] != 1 && map[Hero.stair][dx][dy + 1] != 1 &&
      map[Hero.stair][dx + 1][dy] != 1 &&
      map[Hero.stair][dx + 1][dy + 1] != 1) {
    return 1;
  }
  return 0;
}

void hero_move() {
  if (_kbhit()) {
          switch (_getch()) {
              //up
          case 72:
              if (is_Forbidden(Hero.position_x, Hero.position_y - 10))
                  Hero.position_y -= 10;
              break;
              //down
          case 80:
              if (is_Forbidden(Hero.position_x, Hero.position_y + 10))
                  Hero.position_y += 10;
              break;
              //left
          case 75:
              if (is_Forbidden(Hero.position_x - 10, Hero.position_y))
                  Hero.position_x -= 10;
              break;
              //right
          case 77:
              if (is_Forbidden(Hero.position_x + 10, Hero.position_y))
                  Hero.position_x += 10;
              break;
          }
  }

}