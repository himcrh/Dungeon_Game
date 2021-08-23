#include"Monsters.h"
#include"global.h"

//加载怪物信息
void load_Monster(void) {
  fstream Monster_file;
  Monster_file.open("Monster_file.txt", ios::in);
  if (!Monster_file)
    return;
  freopen("Monster_file.txt", "r", stdin);
  int n;
  scanf_s("%d", &n);
  for (int i = 1; i <= n; i++) {
    Monsters[i].id = i;
    scanf_s("%d %d %d %d", &Monsters[i].HP, &Monsters[i].attack, &Monsters[i].EXP,&Monsters[i].money);
  }
    
  fclose(stdin);
  freopen("CON", "r", stdin);
}
