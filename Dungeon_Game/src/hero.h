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
	int item_yellow, item_blue, item_red;
	int sword;
    int dir;//����������
};
void hero_initial(void);
void hero_move(void);
bool is_Forbidden(int x,int y);
void hero_transfer(int x, int y);
void hero_move_boss(void);
bool is_Forbidden_boss(int x, int y);
void hero_attack(void);
#endif  // !hero