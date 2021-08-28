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
	int item_yellow, item_blue, item_red;
	int sword;
    int dir;//人物面向方向
};
void hero_initial(void);
void hero_move(void);
bool is_Forbidden(int x,int y);
void hero_transfer(int x, int y);
void hero_move_boss(void);
bool is_Forbidden_boss(int x, int y);
void hero_attack(void);
#endif  // !hero