#include"src/global.h"
#pragma comment(lib, "winmm.lib")

int cnt_map;
int map[10][13][13];
int gamestatus;
int smogstatus;
IMAGE img_background;
IMAGE img_test;
IMAGE img_floor,img_floor1;
IMAGE img_wall;
IMAGE img_monsters[7];
IMAGE img_heart,img_peach;
IMAGE img_badheart;
IMAGE img_cloud[5];
IMAGE img_hero[5],img_bighero;
IMAGE img_swordair[5];
IMAGE img_startmenu;
IMAGE img_circle_up;
IMAGE img_circle_down;
IMAGE img_sword;
IMAGE img_pausemenu;
IMAGE img_saved;
IMAGE img_shop;
IMAGE img_shop2;
IMAGE img_shopnpc;
IMAGE img_shoprandom;
IMAGE img_randombox;
IMAGE img_bewar;
IMAGE img_square;
IMAGE img_shopback;
IMAGE img_textfile;
IMAGE img_attackup;
IMAGE img_fire;
IMAGE img_attack4;
IMAGE img_over;
IMAGE img_circle_boss;
IMAGE img_diemenu;
IMAGE img_boss[4];
pair<bool, Monster> show_monster;
void start_initial(void);  //初始化，加载文件
void show(void);
void update_with_input(void);
HERO Hero;
Monster Monsters[7];


int main() {
  start_initial();
  while (gamestatus) {
    while (Hero.HP <= 0) die_menu();
    while (Hero.stair == 7) over_menu();
    while (gamestatus == 2) pause_menu();
    show();
    update_with_input();
  }
  return 0;
}

void start_initial() {
  srand(time(NULL));//随机时间种子
  hero_initial();//英雄初始化
  load_map();//载入地图信息
  load_Monster();//载入monster信息
  initgraph(Width, High);
  setbkmode(TRANSPARENT);
  mciSendString(_T("open musics\\background.mp3 alias bmusic"), NULL, 0, NULL);
  mciSendString(_T("open musics\\merry.mp3 alias menumusic"), NULL, 0, NULL);
  mciSendString(_T("open musics\\windy.mp3 alias wmusic"), NULL, 0, NULL);
  mciSendString(_T("open musics\\got.mp3 alias gmusic"), NULL, 0, NULL);
  mciSendString(_T("open musics\\fight.mp3 alias fmusic"), NULL, 0, NULL);
  mciSendString(_T("open musics\\trans.mp3 alias tmusic"), NULL, 0, NULL);
  mciSendString(_T("open musics\\hurt.mp3 alias hmusic"), NULL, 0, NULL);
  mciSendString(_T("open musics\\flower.mp3 alias diemusic"), NULL, 0, NULL);
  mciSendString(_T("play menumusic repeat"), NULL, 0, NULL);
  loadimage(&img_floor, _T("images\\floor6.png"));
  loadimage(&img_floor1, _T("images\\floor7.png"));
  loadimage(&img_wall, _T("images\\wall1.png"));
  loadimage(&img_hero[1], _T("images\\Link_U.png"));
  loadimage(&img_hero[2], _T("images\\Link_D.png"));
  loadimage(&img_hero[3], _T("images\\Link_L.png"));
  loadimage(&img_hero[4], _T("images\\Link_R.png"));
  loadimage(&img_boss[1], _T("images\\boss_L.png"));
  loadimage(&img_boss[2], _T("images\\boss_R.png"));
  loadimage(&img_monsters[1], _T("images\\monster_1.png"));
  loadimage(&img_monsters[2], _T("images\\monster_2.png"));
  loadimage(&img_monsters[3], _T("images\\monster_3.png"));
  loadimage(&img_monsters[4], _T("images\\monster_4.png"));
  loadimage(&img_monsters[5], _T("images\\monster_5.png"));
  loadimage(&img_heart, _T("images\\heart.png"));
  loadimage(&img_badheart, _T("images\\badheart.png"));
  loadimage(&img_peach, _T("images\\peach.png"));
  loadimage(&img_cloud[1], _T("images\\cloud_1.png"));
  loadimage(&img_cloud[2], _T("images\\cloud_2.png"));
  loadimage(&img_cloud[3], _T("images\\cloud_3.png"));
  loadimage(&img_startmenu, _T("images\\startmenu.png"));
  loadimage(&img_bighero, _T("images\\BigLink.png"));
  loadimage(&img_sword, _T("images\\sword.png"));
  loadimage(&img_saved, _T("images\\saved.png"));
  loadimage(&img_over, _T("images\\overmenu.png"));
  loadimage(&img_circle_up, _T("images\\circle_up.png"));
  loadimage(&img_circle_down, _T("images\\circle_down.png"));
  loadimage(&img_shop, _T("images\\shop.png"));
  loadimage(&img_shop2, _T("images\\shop2.png"));
  loadimage(&img_shopnpc, _T("images\\shopnpc.png"));
  loadimage(&img_shoprandom, _T("images\\shoprandom.png"));
  loadimage(&img_randombox, _T("images\\randombox.png"));
  loadimage(&img_pausemenu, _T("images\\pausemenu.png"));
  loadimage(&img_bewar, _T("images\\bewar.png"));
  loadimage(&img_square, _T("images\\square.png"));
  loadimage(&img_shopback, _T("images\\shopback.png"));
  loadimage(&img_textfile, _T("images\\textfile.png"));
  loadimage(&img_attackup, _T("images\\attackstar.png"));
  loadimage(&img_attack4, _T("images\\Link_R1.png"));
  loadimage(&img_circle_boss, _T("images\\circle_boss.png"));
  loadimage(&img_fire, _T("images\\fire.png"));
  loadimage(&img_swordair[1], _T("images\\swordair_u.png"));
  loadimage(&img_swordair[2], _T("images\\swordair_d.png"));
  loadimage(&img_swordair[3], _T("images\\swordair_l.png"));
  loadimage(&img_swordair[4], _T("images\\swordair_r.png"));
  loadimage(&img_diemenu, _T("images\\gameover.png"));
  BeginBatchDraw();
  while (gamestatus == 0)  start_menu();
}

void show() {
       draw_backgraund();
       draw_fixobject();
       draw_unfixobject();
       if (smogstatus) draw_smog();
       draw_information();
       if (show_monster.first) {
           draw_nomonster();
           draw_monster(show_monster.second);
       }
       drawAlpha(Hero.position_x, Hero.position_y, &img_hero[Hero.dir]);
       
  Sleep(2);
  FlushBatchDraw();
}

void update_with_input(void) {
    hero_move();
}