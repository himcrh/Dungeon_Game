#ifndef Global
#define Global
#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include"easy_draw.h"
#include"hero.h"
#include"scene_draw.h"
#include"Monsters.h"
#include"battle.h"
#include"info_load.h"
using namespace std;
#define High 440
#define Width 880
#define Unit 40
extern int gamestatus;
extern int map[10][13][13];
extern HERO Hero;
extern Monster Monsters[7];
extern IMAGE img_background;
extern IMAGE img_test;
extern IMAGE img_floor;
extern IMAGE img_wall;
extern IMAGE img_monsters[7];
extern IMAGE img_heart, img_peach;
extern IMAGE img_startmenu;
extern IMAGE img_magiccircle;
extern IMAGE img_hero[5],img_bighero;
extern IMAGE img_cloud[5];
extern IMAGE img_circle_up;
extern IMAGE img_circle_down;
extern IMAGE img_sword;
extern IMAGE img_pausemenu;
extern IMAGE img_saved;
extern IMAGE img_bewar;
extern pair<bool, Monster> show_monster;
extern int cnt_map;//µØÍ¼²ãÊý
#endif  // !Global
