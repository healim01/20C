#include <stdio.h>
#include <stdlib.h>

struct menu{
  int no; // 메뉴번호 
  char name[20]; // 메뉴명 
  char madein[20]; // 원산지 
  int price; // 가격 
}; 

void save_menu(struct menu* list[], int size);

int main(void) {
  FILE * file1;
  file1=fopen("menu.txt","w");
  struct menu* mymenu[5]; // 최대 5개까지의 메뉴 
  for (int i=0;i<5;i++) mymenu[i]=malloc(sizeof(struct menu));
  save_menu(mymenu, 5);
  printf("메뉴번호 메뉴이름 원산지 1인분가격\n");
  for (int i=0;i<5;i++) {
    printf("%4d %s %s %d\n",mymenu[i]->no,mymenu[i]->name,mymenu[i]->madein,mymenu[i]->price);
    fprintf(file1,"%4d %s %s %d\n",mymenu[i]->no,mymenu[i]->name,mymenu[i]->madein,mymenu[i]->price);
  }
  
  return 0;
}

void save_menu(struct menu* list[], int size) {
  for (int i=0;i<size;i++) {
    printf("%d번째 메뉴의 번호, 메뉴명, 원산지, 가격? ",i+1);
    scanf("%d %s %s %d",&list[i]->no,list[i]->name,list[i]->madein,&list[i]->price);
  }
}