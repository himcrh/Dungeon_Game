#ifndef SCENE_DRAW
#define SCENE_DRAW
#include"global.h"
void draw_backgraund(void);
void draw_fixobject(void);
void draw_unfixobject(void);
void draw_information(void);
void draw_nomonster(void);
void draw_monster(struct Monster cur_M);
void draw_smog(void);
void start_menu(void);
void pause_menu(void);
void over_menu(void);
void gameover(void);
void draw_shop(void);//�̵���ƣ������̵����ѭ��
void draw_randomshop(void);//����̵�
bool draw_vschoice(int cur_monster);//�Ƿ񹥻�������ƣ��������ѭ��
void draw_vs_boss(void);
#endif