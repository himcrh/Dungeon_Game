#ifndef hero
#define hero
#include<graphics.h>
#include<conio.h>
//定义HERO
struct HERO {
	int position_x, position_y;
	int HP;
	int attack;
	int EXP;
    int stair;//当前所处层数
	int Level;
	int money;
	int key_yellow, key_blue, key_red;
};

void hero_move(void);
bool is_Forbidden(int x,int y);
#endif  // !hero