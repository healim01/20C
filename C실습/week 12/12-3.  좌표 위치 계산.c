#include <stdio.h>
#include <stdlib.h>
 struct point{ 
      float x; // x좌표 값 
      float y; // y좌표 값 
}; 

int main(void) {
  struct point *mypoint[10];
  int part[10], count[4]={0};
  for (int i=0;i<10;i++) {
    mypoint[i]=malloc(sizeof(struct point));
    
    printf("%d번째 좌표의 x, y값?",i+1);
    scanf("%f %f",&mypoint[i]->x, &mypoint[i]->y);
    if (mypoint[i]->x>=0) {
      if (mypoint[i]->y>=0) part[i]=1;
      else part[i]=4;
    }
    else {
      if (mypoint[i]->y>=0) part[i]=2;
      else part[i]=3;
    }
  }
  for (int i=0;i<10;i++) {
    printf("%d번째 좌표 %d사분면에 위치\n",i+1,part[i]);
    if (part[i]==1) count[0]++;
    else if (part[i]==2) count[1]++;
    else if (part[i]==3) count[2]++;
    else count[3]++;
  }
  for (int i=0;i<4;i++) printf("%d사분면의 좌표는 모두 %d개\n",i+1,count[i]);
  
  return 0;
}