#ifndef hero
#define hero
#include<graphics.h>
#include<conio.h>
//����HERO
struct HERO {
	int position_x, position_y;
	int HP;
	int attack;
	int EXP;
    int stair;//��ǰ��������
	int Level;
	int money;
	int key_yellow, key_blue, key_red;
};

void hero_move(void);
bool is_Forbidden(int x,int y);
#endif  // !hero