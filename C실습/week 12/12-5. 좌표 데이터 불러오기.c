#include <stdio.h>
#include <stdlib.h>

struct point{ 
     float x; // x좌표 값 
     float y; // y좌표 값 
}; 
int load_point(struct point* list[]); 

int main(void) {
  struct point* mypoint[50];  // 최대 50 개의 좌표 구조체를 관리할 수 있음. 
  int part[4], count[4]={0};
  int num;
  
  for (int i=0;i<50;i++) mypoint[i]=malloc(sizeof(struct point));
  num=load_point(mypoint);

  
  
  for (int i=0;i<num;i++) {
    if (mypoint[i]->x>=0) {
      if (mypoint[i]->y>=0) {
        part[i]=1;
        count[0]++;
      }
      else {
        part[i]=4;
        count[3]++;
      }
    }
    else {
      if (mypoint[i]->y>=0) {
        part[i]=2;
        count[1]++;
      }
      else {
        part[i]=3;
        count[2]++;
      }
    }
    printf("%d번째 좌표 (%.1f, %.1f) %d사분면에 위치\n",i+1,mypoint[i]->x,mypoint[i]->y,part[i]);
  }
  for (int i=0;i<4;i++) printf("%d사분면의 좌표는 모두 %d개\n",i+1,count[i]);
  
  return 0;
}

int load_point(struct point* list[]) {
  FILE * file1;
  int i;
  file1=fopen("point.txt","r");
  
  for (i=0;i<50;i++) {
    fscanf(file1,"%f %f",&list[i]->x, &list[i]->y);
    if (feof(file1)) break;
  }
  printf("point.txt에서 %d개의 좌표 정보를 읽었습니다.\n",i);
  
  return i;
}

