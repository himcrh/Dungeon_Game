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
#include<vector>
using namespace std;
#define High 440
#define Width 880
#define Unit 40
extern int gamestatus;
extern int map[10][13][13];
extern HERO Hero;
extern Monster Monsters[7];
extern BOSS boss_1;
extern IMAGE img_background;
extern IMAGE img_test;
extern IMAGE img_floor,img_floor1;
extern IMAGE img_wall;
extern IMAGE img_monsters[7];
extern IMAGE img_heart, img_peach;
extern IMAGE img_startmenu;
extern IMAGE img_magiccircle;
extern IMAGE img_hero[5],img_bighero;
extern IMAGE img_swordair[5];
extern IMAGE img_cloud[5];
extern IMAGE img_circle_up;
extern IMAGE img_circle_down;
extern IMAGE img_circle_boss;
extern IMAGE img_sword;
extern IMAGE img_pausemenu;
extern IMAGE img_saved;
extern IMAGE img_shop;
extern IMAGE img_shop2;
extern IMAGE img_shopnpc;
extern IMAGE img_shoprandom;
extern IMAGE img_bewar;
extern IMAGE img_square;
extern IMAGE img_shopback;
extern IMAGE img_textfile;
extern IMAGE img_randombox;
extern IMAGE img_attackup;
extern IMAGE img_badheart;
extern IMAGE img_fire;
extern IMAGE img_over;
extern IMAGE img_attack4;
extern pair<bool, Monster> show_monster;
extern int cnt_map;//µØÍ¼²ãÊý
extern vector<SWORDAIR> swordairs;
#endif  // !Global
