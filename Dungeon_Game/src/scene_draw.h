#ifndef SCENE_DRAW
#define SCENE_DRAW
#include"global.h"
void draw_backgraund(void);
void draw_fixobject(void);
void draw_unfixobject(void);
void draw_information(void);
void draw_nomonster(void);
void draw_monster(struct Monster cur_M);
void load_map(void);
void start_menu(void);
#endif