#include "scene_draw.h"
//开始界面绘制
void start_menu() {
    drawAlpha(0, 0, &img_startmenu);
    setbkmode(TRANSPARENT);
    settextstyle(30, 0, _T("黑体"));
    settextcolor(BLUE);
    outtextxy(Width * 0.35, High * 5.2 / 8, _T("1 ENTER THE GAME"));
    settextcolor(CYAN);
    outtextxy(Width * 0.35, High * 6 / 8, _T("2 READ THE SAVE"));
    settextcolor(MAGENTA);
    outtextxy(Width * 0.35, High * 6.8 / 8, _T("3 QUIT"));
    FlushBatchDraw();
    Sleep(2);
    if (_kbhit()) {
        char input = _getch();
        if (input == '1') {
            gamestatus = 1;
            mciSendString(_T("close menumusic "), NULL, 0, NULL);
            mciSendString(_T("play bmusic repeat"), NULL, 0, NULL);
        }
        else if (input == '2') {
            read_info();
            gamestatus = 1;
            mciSendString(_T("close menumusic "), NULL, 0, NULL);
            mciSendString(_T("play bmusic repeat"), NULL, 0, NULL);
        }
        else if (input == '3') {
          gameover();
        }
    }
}
//暂停界面绘制
void pause_menu() {
    drawAlpha(0, 0, &img_pausemenu);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(30, 0, _T("黑体"));
    settextcolor(BLUE);
    outtextxy(Width * 0.35, High * 5.2 / 8, _T("PRESS ESC TO ENTER GAME"));
    settextcolor(BROWN);
    outtextxy(Width * 0.35, High * 6 / 8, _T("2 SAVE"));
    settextcolor(MAGENTA);    
    outtextxy(Width * 0.35, High * 6.8 / 8, _T("3 QUIT"));
    FlushBatchDraw();
    Sleep(2);
    while (_kbhit()) {
        switch (_getch()) {
        case 27:
            gamestatus = 1;
            break;
        case '2':
            save_info();
            drawAlpha(0, 0, &img_saved);
            FlushBatchDraw();
            Sleep(1000);
            break;
        case '3':
          gameover();
        }
    }
}
void over_menu() {
    drawAlpha(0, 0, &img_over);
    mciSendString(_T("close bmusic"), NULL, 0, NULL);
    mciSendString(_T("open musics\\merry.mp3 alias menumusic"), NULL, 0, NULL);
    mciSendString(_T("play menumusic repeat"), NULL, 0, NULL);

    FlushBatchDraw();
    while (_kbhit()) {
        if (_getch() == ' ') gameover(); 
    }
}
//地图背景绘制
void draw_backgraund(void) {
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      drawAlpha(i*Unit,j*Unit, &img_floor);
    }
  }
}
//场景绘制
void draw_fixobject(void) {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            switch (map[Hero.stair][i][j]) {
            case 1:
                drawAlpha(i * Unit, j * Unit, &img_wall);
                break;
            case 2:
                drawAlpha(i * Unit, j * Unit, &img_circle_down);
                break;
            case 3:
                drawAlpha(i * Unit, j * Unit, &img_circle_up);
                break;
            case 4:
                drawAlpha(i * Unit, j * Unit, &img_shop);
                break;
            case 5:
                drawAlpha(i * Unit, j * Unit, &img_peach);
                break;
            case 6:
               drawAlpha(i * Unit, j * Unit, &img_heart);
               break;
            case 7:
                drawAlpha(i * Unit, j * Unit, &img_attackup);
                break;
            case 8:
                drawAlpha(i * Unit, j * Unit, &img_shop2);
                break;
            case 9:
                drawAlpha(i * Unit, j * Unit, &img_badheart);
                break;
            case 10:
                drawAlpha(i * Unit, j * Unit, &img_fire);
                break;

            }
        }
    }
}
void draw_unfixobject(void) {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            if (map[Hero.stair][i][j] > 10 && map[Hero.stair][i][j] <= 90)
                drawAlpha(i * Unit, j * Unit, &img_monsters[map[Hero.stair][i][j] - 10]);
        }
    }
}
//怪物交战绘制

//打不过
void draw_nomonster(void) {

    settextcolor(RED);
    settextstyle(30, 0, _T("Helvetica"));
    outtextxy(Width * 0.76, High * 0.1, _T("RUN,MY BOY!!!"));
}
//打得过，绘制交战过程
void draw_monster(Monster cur_M) {
    int x = cur_M.id;
    drawAlpha(Width * 0.56, High * 0.3,&img_monsters[x]);
    drawAlpha(Width * 0.52, High * 0.1, &img_bewar);
    settextcolor(WHITE);
    settextstyle(30, 0, _T("Helvetica"));
    TCHAR s[10];
    outtextxy(Width * 0.76, High * 0.2, _T("HP:"));
    _stprintf_s(s, _T("%d"), cur_M.HP);
    if (cur_M.HP < 100) settextcolor(RED);
    outtextxy(Width * 0.82, High * 0.2, s);
    settextcolor(WHITE);
    outtextxy(Width * 0.76, High * 0.3, _T("ATK:"));
    _stprintf_s(s, _T("%d"), cur_M.attack);
    outtextxy(Width * 0.84, High * 0.3, s);
    outtextxy(Width * 0.76, High * 0.4, _T("EXP:"));
    _stprintf_s(s, _T("%d"), cur_M.EXP);
    outtextxy(Width * 0.84, High * 0.4, s);
    Sleep(200);
}
//英雄信息绘制
void draw_information(void) {
    for (int i = 11; i <= 21; i++) {
        for (int j = 0; j <= 10; j++) {
            drawAlpha(i * Unit, j * Unit, &img_floor1);
        }
    }
    TCHAR s[10];
    setcolor(WHITE);
    settextstyle(30, 0, _T("Helvetica"));
    rectangle(440, 0, 880, 220);
    outtextxy(450, 5, _T("Floor :"));
    _stprintf_s(s, _T("%d"), Hero.stair);
    outtextxy(530, 5, s);
    rectangle(440, 220, 880, 440);
    //道具绘制
    rectangle(780, 240, 860, 400);
    if (Hero.sword) drawAlpha(780, 240, &img_sword);
    line(820, 240, 820, 400);
    line(780, 280, 860, 280);
    if (Hero.item_blue) drawAlpha(780, 280, &img_cloud[1]);
    line(780, 320, 860, 320);
    if (Hero.item_red) drawAlpha(780, 320, &img_cloud[2]);
    line(780, 360, 860, 360);
    if (Hero.item_yellow)drawAlpha(780, 360, &img_cloud[3]);
    settextcolor(WHITE);
    outtextxy(Width * 0.52, High * 0.52, _T("HP:"));
    outtextxy(Width * 0.52, High * 0.62, _T("ATK:"));
    outtextxy(Width * 0.52, High * 0.72, _T("EXP:"));
    outtextxy(Width * 0.52, High * 0.82, _T("MONEY:"));
    settextcolor(GREEN);
    if (Hero.HP < 300) settextcolor(RED);
    _stprintf_s(s, _T("%d"), Hero.HP);
    outtextxy(Width * 0.58, High * 0.52, s);
    settextcolor(GREEN);
    _stprintf_s(s, _T("%d"), Hero.attack);
    outtextxy(Width * 0.6, High * 0.62, s);
    _stprintf_s(s, _T("%d"), Hero.EXP);
    outtextxy(Width * 0.6, High * 0.72, s);
    _stprintf_s(s, _T("%d"), Hero.money);
    outtextxy(Width * 0.64, High * 0.82, s);
    settextcolor(BLUE);
    outtextxy(Width * 0.52, High * 0.92, _T("Welcome to the wonderland!"));
    outtextxy(Width * 0.79, High * 0.52, _T("Lv: "));
    _stprintf_s(s, _T("%d"), Hero.Level);
    outtextxy(Width * 0.83, High * 0.52, s);
    drawAlpha(Width * 0.7,High * 0.57, &img_bighero);
}

void gameover() {
  EndBatchDraw();
  closegraph();
  exit(0);
}

//商店的绘制
void draw_shop(void) {
    mciSendString(_T("open musics\\windy.mp3 alias wmusic"), NULL, 0, NULL);
    mciSendString(_T("play wmusic"), NULL, 0, NULL);
    int cur = 1;//光标的位置(默认)
    int w_flag = 1;
    int canafford1 = 1,canafford2 = 1;
    while (w_flag) {
      draw_information();
      drawAlpha(0.52 * Width, 50, &img_peach);
      drawAlpha(0.52 * Width, 100, &img_heart);
      drawAlpha(0.52 * Width, 150, &img_shopback);
      drawAlpha(0.64 * Width, 10, &img_textfile);
      settextcolor(BLACK);
      if (cur < 3) {
              
              if (cur == 1&&canafford1) {
                  settextstyle(20, 0, _T("Helvetica"));
                  outtextxy(0.66 * Width, 20, _T("Choose this one?"));
                  setcolor(BLUE);
                  outtextxy(0.66 * Width, 48, _T("50"));
                  setcolor(RED);
                  outtextxy(0.70 * Width, 48, _T("+50/80HP"));
              }
              else if(cur == 2&&canafford2) {
                  settextstyle(20, 0, _T("Helvetica"));
                  outtextxy(0.66 * Width, 20, _T("Choose this one?"));
                  setcolor(BLUE);
                  outtextxy(0.66 * Width, 48, _T("80"));
                  setcolor(RED);
                  outtextxy(0.70 * Width, 48, _T("+100HP"));
              }
          else {
              settextstyle(20, 0, _T("黑体"));
              outtextxy(0.67 * Width, 22, _T("CAN'T AFFORD,BYE!!!"));
          }
      }
      else {
          settextstyle(40, 0, _T("黑体"));
          outtextxy(0.71 * Width, 22, _T("Leave?"));
      }
      //canafford = 1;
      drawAlpha(0.89 * Width, 0.16 * High, &img_shopnpc);
            if (_kbhit()) {
                switch (_getch()){
                case 72:
                    cur--;
                    if (cur == 0) cur = 3;
                    break;
                case 80:
                    cur++;
                    if (cur > 3) cur -= 3;
                    break;
                case 32:
                    if (cur == 3) {
                        w_flag = 0;
                        mciSendString(_T("close wmusic"), NULL, 0, NULL);
                    }
                    if (cur == 1) {
                        if (Hero.money >= 50) {
                            Hero.money -= 50;
                            if (Hero.HP < 300) Hero.HP += 80;
                            else  Hero.HP += 50;
                        }
                        else canafford1 = 0;
                    }
                    if(cur == 2) {
                        if (Hero.money >= 80) {
                            Hero.money -= 80;
                            Hero.HP += 100;
                        }
                        else canafford2 = 0;
                    }
                    break;
                }
            }
            drawAlpha(0.52 * Width, cur * 50, &img_square);
            FlushBatchDraw();
    }
}

void draw_randomshop() {
    mciSendString(_T("open musics\\windy.mp3 alias wmusic"), NULL, 0, NULL);
    mciSendString(_T("play wmusic"), NULL, 0, NULL);
    int cur = 1;//光标的位置(默认)
    int w_flag = 1;
    int canafford = 1;
    while (w_flag) {
        draw_information();
        drawAlpha(0.52 * Width, 75, &img_randombox);
        drawAlpha(0.52 * Width, 125, &img_shopback);
        drawAlpha(0.64 * Width, 10, &img_textfile);
        settextcolor(BLACK);
        if (cur == 1) {

            if (canafford) {
                settextstyle(20, 0, _T("Helvetica"));
                outtextxy(0.66 * Width, 20, _T("GOOD LUCK!"));
                setcolor(BLUE);
                outtextxy(0.66 * Width, 48, _T("75"));
                setcolor(RED);
                outtextxy(0.70 * Width, 48, _T("FOR ONE TRY"));

            }
            else {
                settextstyle(20, 0, _T("黑体"));
                outtextxy(0.67 * Width, 22, _T("CAN'T AFFORD,BYE!!!"));
            }
        }
        else {
            settextstyle(40, 0, _T("黑体"));
            outtextxy(0.71 * Width, 22, _T("Leave?"));
        }
        drawAlpha(0.89 * Width, 0.16 * High, &img_shoprandom);
        if (_kbhit()) {
            switch (_getch()) {
            case 72:
                cur--;
                if (cur == 0) cur = 2;
                break;
            case 80:
                cur++;
                if (cur > 2) cur -= 2;
                break;
            case 32:
                if (cur == 2) {
                    w_flag = 0;
                    mciSendString(_T("close wmusic"), NULL, 0, NULL);
                }

                if (cur == 1) {
                    if (Hero.money >= 75) {
                        Hero.money -= 75;
                        Hero.HP += 50 * (rand() % 4);
                    }
                    else canafford = 0;
                }
                break;
            }

        }
    
    drawAlpha(0.52 * Width, cur * 50+25, &img_square);
    FlushBatchDraw();
    }
}
//交战选择界面
bool draw_vschoice(int cur_monster) {
  int cur = 1;  //光标的位置(默认)
  while (true) {
    draw_information();

    drawAlpha(0.52 * Width, 75, &img_bewar);
    drawAlpha(0.52 * Width, 125, &img_shopback);
    drawAlpha(0.68 * Width, 100, &img_monsters[cur_monster]);
    settextcolor(WHITE);
    settextstyle(30, 0, _T("Helvetica"));
    TCHAR s[10];
    outtextxy(Width * 0.76, High * 0.2, _T("HP:"));
    _stprintf_s(s, _T("%d"), Monsters[cur_monster].HP);
    outtextxy(Width * 0.82, High * 0.2, s);
    settextcolor(WHITE);
    outtextxy(Width * 0.76, High * 0.3, _T("ATK:"));
    _stprintf_s(s, _T("%d"), Monsters[cur_monster].attack);
    outtextxy(Width * 0.84, High * 0.3, s);
    outtextxy(Width * 0.76, High * 0.4, _T("EXP:"));
    _stprintf_s(s, _T("%d"), Monsters[cur_monster].EXP);
    outtextxy(Width * 0.84, High * 0.4, s);

    settextcolor(BLACK);
    if (_kbhit()) {
      switch (_getch()) {
        case 72:
          cur--;
          if (cur == 0)
            cur = 2;
          break;
        case 80:
          cur++;
          if (cur > 2)
            cur -= 2;
          break;
        case 32:
          if (cur == 2) {
            return false;
          }
          if (cur == 1) {
              mciSendString(_T("close fmusic"), NULL, 0, NULL);
              mciSendString(_T("open musics\\fight.mp3 alias fmusic"), NULL, 0, NULL);
              mciSendString(_T("play fmusic"), NULL, 0, NULL);
            return true;
          }
          break;
      }
    }
    drawAlpha(0.52 * Width, cur * 50 + 25, &img_square);
    FlushBatchDraw();
  }
}

void draw_vs_boss(void) {
  draw_backgraund();
  drawAlpha(Hero.position_x, Hero.position_y, &img_hero[Hero.dir]);
  FlushBatchDraw();
}
