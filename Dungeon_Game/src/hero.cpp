#include "hero.h"
int isForbidden() {
	//÷Æ∫Û‘ŸœÍœ∏–¥
	return 0;
}
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

}