#ifndef hero
#define hero
#include<graphics.h>
#include<conio.h>
struct HERO {
	float position_x, position_y;
	int HP;
	int attack;
	int defence;
	int EXP;
	int Level;
	int money;
	int key_yellow, key_blue, key_red;
}Hero;
//∂®“ÂHero
void hero_move(void);
int isForbidden();
#endif  // !hero