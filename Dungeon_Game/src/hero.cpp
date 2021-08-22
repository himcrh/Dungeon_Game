#include "hero.h"
#include"global.h"
#include"math.h"
//int map[10][13][13];
bool is_Forbidden(int x, int y) {
    if (x * y < 0 || canvas[x][y] == 1 || canvas[x + 40][y] == 1 || canvas[x][y + 40] == 1 || canvas[x + 40][y + 40] == 1) return 0;
    return 1;
}
void hero_move() {
  if (_kbhit()) {
    switch (_getch()) {
	  //up
      case 72:
        if (is_Forbidden(Hero.position_x, Hero.position_y - 5))

          Hero.position_y -= 5;
        break;
	  //down
      case 80:
        if (is_Forbidden(Hero.position_x, Hero.position_y + 5))
          Hero.position_y += 5;
        break;
	  //left
      case 75:
        if (is_Forbidden(Hero.position_x - 5,Hero.position_y))
          Hero.position_x -= 5;
        break;
	  //right
      case 77:
        if (is_Forbidden(Hero.position_x + 5,Hero.position_y))
          Hero.position_x += 5;
        break;
    }
  }

}