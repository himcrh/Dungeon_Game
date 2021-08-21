#include "hero.h"
#include"global.h"

//int map[10][13][13];
bool is_Forbidden(int x, int y) {
  if (map[1][x][y] == 0)
    return 1;
  return 0;
}
<<<<<<< HEAD
void hero_move() {
  if (_kbhit()) {
    switch (_getch()) {
	  //up
      case 72:
        if (is_Forbidden((int)Hero.position_x, (int)Hero.position_y - 1))
          Hero.position_y -= 0.25;
        break;
	  //down
      case 80:
        if (is_Forbidden((int) Hero.position_x, (int)Hero.position_y + 1))
          Hero.position_y += 0.25;
        break;
	  //left
      case 75:
        if (is_Forbidden((int) Hero.position_x - 1, (int)Hero.position_y))
          Hero.position_x -= 0.25;
        break;
	  //right
      case 77:
        if (is_Forbidden((int) Hero.position_x + 1, (int)Hero.position_y))
          Hero.position_x += 0.25;
        break;
    }
  }
=======
void hero_move() 
{
	if (_kbhit())
	{
			char input = _getch();
			if (input == 'a'&&isForbidden()) Hero.position_x -= 0.25;
			else if (input == 'd'&&isForbidden()) Hero.position_x += 0.25;
			else if (input == 'w'&&isForbidden()) Hero.position_y -= 0.25;
			else if (input == 's'&&isForbidden()) Hero.position_y += 0.25;
	}
>>>>>>> 1e370c3efc7cdf9ccf2584c949c4821e4e3c9cfc

}