#include"battle.h"
//�ж��ܷ���
bool vs_cmp(int cur_monster,int x,int y) {
  //���ǹ���ǵ��߻�����
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
  if (cnt_a <= cnt_b) {//�ܴ��
    if (whether_attack(cur_monster)) {
      //�������
      battle_details(cur_monster, x, y);
      return true;
    } else
    return false;
  }
  
  show_monster.second = Monsters[cur_monster];//�򲻹�
  show_monster.first = true;//�ж��Ƿ��ù�
  return false;
}
//�ܴ������ʾ��սϸ��
void battle_details(int cur_monster,int x,int y) {
  Monster cur_M = Monsters[cur_monster];
  //��ȡ��һ��moster
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
  //����cur_monster������ʾ������Ϣ
  //��������Ļ����� true
  //���������� false
  if (draw_vschoice(cur_monster))
    return true;
  else
    return false;
}
