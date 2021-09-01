#include "hero.h"
#include"global.h"
clock_t time_swordair = clock();
vector<SWORDAIR> swordairs;
//Ӣ����Ϣ��ʼ��
void hero_initial(void) {
    Hero.HP = 500;
    Hero.attack = 50;
    Hero.stair = 1;
    Hero.Level = 1;
    Hero.dir = 4;
    Hero.sword = 1;
    Hero.item_yellow = 1;
    Hero.item_blue = 1;
    Hero.item_red = 1;
}

//�����Ƿ��ܹ���ͨ��
bool is_Forbidden(int x, int y) {
  show_monster.first = false;
  if (x < 0 || y < 0 || x>400 || y>400) return 0;
  //dir up - 1; down - 2; left - 3; right - 4;
  int dx = x / 40;
  int dy = y / 40;
  
  if (x % 40 == 0 && y % 40 == 0) return 1;
  if (x % 40 == 0) {
    if (map[Hero.stair][dx][dy] != 1 && map[Hero.stair][dx][dy + 1] != 1) {
      //����������ǽ
      if (vs_cmp(map[Hero.stair][dx][dy],dx,dy) &&
          vs_cmp(map[Hero.stair][dx][dy + 1], dx, dy+1)) {
        return 1;
      }
    }
      
  }
  else if (y % 40 == 0) {
    if (map[Hero.stair][dx][dy] != 1 && map[Hero.stair][dx + 1][dy] != 1) {
      if (vs_cmp(map[Hero.stair][dx][dy], dx, dy) &&
          vs_cmp(map[Hero.stair][dx + 1][dy], dx+1, dy)) {
        return 1;
      }
    }
  }
  /*
  if (map[Hero.stair][dx][dy] ==0 && map[Hero.stair][dx][dy + 1] == 0 &&
      map[Hero.stair][dx + 1][dy] ==0 &&
      map[Hero.stair][dx + 1][dy + 1] ==0) {
    return 1;
  }*/
  
  else if (map[Hero.stair][dx][dy] != 1 && map[Hero.stair][dx][dy + 1] != 1 &&
      map[Hero.stair][dx + 1][dy] != 1 &&
      map[Hero.stair][dx + 1][dy + 1] != 1) {
    if (vs_cmp(map[Hero.stair][dx][dy], dx, dy) &&
      vs_cmp(map[Hero.stair][dx + 1][dy], dx + 1, dy) &&
      vs_cmp(map[Hero.stair][dx+1][dy+1], dx+1, dy+1) &&
      vs_cmp(map[Hero.stair][dx][dy + 1], dx, dy + 1)) {
    return 1;
    }
  }
  
  return 0;
}

//Ӣ���ƶ�
void hero_move() {
    if (_kbhit()) {
        switch (_getch()) {
            //up
        case 72:
            Hero.dir = 1;
            if (is_Forbidden(Hero.position_x, Hero.position_y - 10))
                Hero.position_y -= 10;
            break;
            //down
        case 80:
            Hero.dir = 2;
            if (is_Forbidden(Hero.position_x, Hero.position_y + 10))
                Hero.position_y += 10;
            break;
            //left
        case 75:
            Hero.dir = 3;
            if (is_Forbidden(Hero.position_x - 10, Hero.position_y))
                Hero.position_x -= 10;
            break;
            //right
        case 77:
            Hero.dir = 4;
            if (is_Forbidden(Hero.position_x + 10, Hero.position_y))
                Hero.position_x += 10;
            break;
            //space(������)
        case 32:
            hero_transfer(Hero.position_x, Hero.position_y);
            break;
            //pause(��ͣ)        
        case 27:
            gamestatus = 2;
            break;
        }
    }

}

//����
void hero_transfer(int x, int y) {
    if (x % 40 || y % 40)
        return;
    
  x /= 40;
  y /= 40;
  //���д���
  if (map[Hero.stair][x][y] == 2) {
      mciSendString(_T("close tmusic"), NULL, 0, NULL);
      mciSendString(_T("open musics\\trans.mp3 alias tmusic"), NULL, 0, NULL);
      mciSendString(_T("play tmusic"), NULL, 0, NULL);
    Hero.stair--;
    for (int i = 0; i <= 10; i++) {
      for (int j = 0; j <= 10; j++) {
        if (map[Hero.stair][i][j] == 3) {
          Hero.position_x = i * 40;
          Hero.position_y = j * 40;
        }
      }
    }
    return;
  }
  //���д���
  if (map[Hero.stair][x][y] == 3) {
      mciSendString(_T("close tmusic"), NULL, 0, NULL);
      mciSendString(_T("open musics\\trans.mp3 alias tmusic"), NULL, 0, NULL);
      mciSendString(_T("play tmusic"), NULL, 0, NULL);
    Hero.stair++;
    for (int i = 0; i <= 10; i++) {
      for (int j = 0; j <= 10; j++) {
        if (map[Hero.stair][i][j] == 2) {
          Hero.position_x = i * 40;
          Hero.position_y = j * 40;
        }
      }
    }
    return;
  }
  //�̵괫��
  if (map[Hero.stair][x][y] == 4) {
    mciSendString(_T("close bmusic"), NULL, 0, NULL);

    draw_shop();//���뵽�̵����ҳ��
    mciSendString(_T("open musics\\background.mp3 alias bmusic"), NULL, 0, NULL);
    mciSendString(_T("play bmusic repeat"), NULL, 0, NULL);
    return;
  }
  if (map[Hero.stair][x][y] == 8) {
      mciSendString(_T("close bmusic"), NULL, 0, NULL);

      draw_randomshop();//��������̵�
      mciSendString(_T("open musics\\background.mp3 alias bmusic"), NULL, 0, NULL);
      mciSendString(_T("play bmusic repeat"), NULL, 0, NULL);
      return;
  }
  //Boss�ؿ�����
  if (map[Hero.stair][x][y] == 101) {
    vs_boss(boss_1);
    return;
  }
}

void hero_move_boss(void) {
  if (_kbhit()) {
    switch (_getch()) {
        // up
      case 72:
        Hero.dir = 1;
        if (is_Forbidden_boss(Hero.position_x, Hero.position_y - 10))
          Hero.position_y -= 10;
        break;
        // down
      case 80:
        Hero.dir = 2;
        if (is_Forbidden_boss(Hero.position_x, Hero.position_y + 10))
          Hero.position_y += 10;
        break;
        // left
      case 75:
        Hero.dir = 3;
        if (is_Forbidden_boss(Hero.position_x - 10, Hero.position_y))
          Hero.position_x -= 10;
        break;
        // right
      case 77:
        Hero.dir = 4;
        if (is_Forbidden_boss(Hero.position_x + 10, Hero.position_y))
          Hero.position_x += 10;
        break;
        // space(������)
      case 32:
        hero_attack();
        break;
    }
  }
}

bool is_Forbidden_boss(int x, int y) {
  if (x < 0 || y < 0 || x > 400 || y > 400)
    return FALSE;
  return true;
}

void hero_attack(void) {
  double d_time = (double)(clock() - time_swordair) / CLOCKS_PER_SEC;
  if (d_time > 0.2) {
    swordairs.push_back({Hero.position_x, Hero.position_y, 1, Hero.dir});
    time_swordair = clock();
  }
}


void hero_die(void) {
        drawAlpha(0, 0, &img_diemenu);
        FlushBatchDraw();
        mciSendString(_T("close bmusic"), NULL, 0, NULL);
        mciSendString(_T("open musics\\merry.mp3 alias diemusic"), NULL, 0, NULL);
        mciSendString(_T("play diemusic repeat"), NULL, 0, NULL);
        while (_kbhit()) {
            if(_getch() == ' ') gameover();
        }
}

