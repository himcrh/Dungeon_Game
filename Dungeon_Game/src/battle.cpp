#include"battle.h"
//判断能否打过
bool vs_cmp(int cur_monster,int x,int y) {
  //不是怪物，是道具或其他
  if (cur_monster > 90 || cur_monster <= 10) {
      //peach
    if (cur_monster == 5) {
    mciSendString(_T("close gmusic"), NULL, 0, NULL);
    mciSendString(_T("open musics\\got.mp3 alias gmusic"), NULL, 0, NULL);
    mciSendString(_T("play gmusic"), NULL, 0, NULL);
    if (Hero.HP < 300) Hero.HP += 80;
    else  Hero.HP += 50;
      map[Hero.stair][x][y] = 0;
    }
    //heart
    if (cur_monster == 6) {   
    mciSendString(_T("close gmusic"), NULL, 0, NULL);
    mciSendString(_T("open musics\\got.mp3 alias gmusic"), NULL, 0, NULL);
    mciSendString(_T("play gmusic"), NULL, 0, NULL);
      Hero.HP += 100;
      map[Hero.stair][x][y] = 0;
    }
    //star
    if (cur_monster == 7) {
    mciSendString(_T("close gmusic"), NULL, 0, NULL);
    mciSendString(_T("open musics\\got.mp3 alias gmusic"), NULL, 0, NULL);
    mciSendString(_T("play gmusic"), NULL, 0, NULL);
      Hero.HP += 100;
      Hero.attack += 30;
      map[Hero.stair][x][y] = 0;
    }
    //badheart
    if (cur_monster == 9) {
        mciSendString(_T("close gmusic"), NULL, 0, NULL);
        mciSendString(_T("open musics\\got.mp3 alias gmusic"), NULL, 0, NULL);
        mciSendString(_T("play gmusic"), NULL, 0, NULL);
        Hero.HP += 30;
        Hero.attack -= 40;
        map[Hero.stair][x][y] = 0;
    }

    return true;
  } 
    
  cur_monster -= 10;
  int cnt_a; 
  cnt_a = Monsters[cur_monster].HP / Hero.attack;
  if (Monsters[cur_monster].HP % Hero.attack)
    cnt_a++;
  
  int cnt_b;
  cnt_b = Hero.HP / Monsters[cur_monster].attack;
  if (Hero.HP % Monsters[cur_monster].attack)
    cnt_b++;
  if (cnt_a <= cnt_b) {//能打过
    if (whether_attack(cur_monster)) {
      //如果攻击
      battle_details(cur_monster, x, y);
      return true;
    } else
    return false;
  }
  
  show_monster.second = Monsters[cur_monster];//打不过
  show_monster.first = true;//判断是否打得过
  return false;
}
//能打过，显示交战细节
void battle_details(int cur_monster,int x,int y) {
  Monster cur_M = Monsters[cur_monster];
  //提取出一个moster
  while (cur_M.HP > 0) {
    cur_M.HP -= Hero.attack;
    if (cur_M.HP > 0)
      Hero.HP -= cur_M.attack;
    draw_backgraund();
    draw_information();
    draw_monster(cur_M);
    draw_fixobject();
    draw_unfixobject();
    drawAlpha(Hero.position_x, Hero.position_y, &img_hero[Hero.dir]);
    FlushBatchDraw();
    Sleep(200);
  }
  map[Hero.stair][x][y] = 0;
  Hero.EXP += cur_M.EXP;
  while (Hero.EXP > 100) {
      Hero.EXP -= 100;
      Hero.Level++;
      Hero.attack += 10;
  }
  Hero.money += cur_M.money;
}

bool whether_attack(int cur_monster) {
  //传入cur_monster用于显示怪物信息
  //如果攻击的话返回 true
  //不攻击返回 false
  if (draw_vschoice(cur_monster))
    return true;
  else
    return false;
}
