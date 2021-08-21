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

#define High 440
#define Width 880
#define Unit 40

extern int map[10][13][13];
extern HERO Hero;
extern IMAGE img_background;
extern IMAGE img_test;
extern IMAGE img_floor;
extern IMAGE img_wall;
extern IMAGE img_monster_1, img_monster_2, img_monster_3, img_monster_4,
    img_monster_5;
extern IMAGE img_hero;
#endif  // !Global
