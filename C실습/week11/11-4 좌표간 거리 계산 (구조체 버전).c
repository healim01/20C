#include <stdio.h>
#include <math.h>

struct point{ 
     float x; // x좌표 값 
     float y; // y좌표 값 
}; 

int main(void) {
  struct point n1, n2;
  float dist;
  
  printf("첫번째 좌표의 x값? ");
  scanf("%f",&n1.x);
  printf("첫번째 좌표의 y값? ");
  scanf("%f",&n1.y);
  printf("두번째 좌표의 x값? ");
  scanf("%f",&n2.x);
  printf("두번째 좌표의 y값? ");
  scanf("%f",&n2.y);
  
  if (n2.x>n1.x) dist=sqrt(pow(n2.x-n1.x,2)+pow(n2.y-n1.y,2));
  else dist=sqrt(pow(n1.x-n2.x,2)+pow(n1.y-n2.y,2));
  
  printf("\n두 좌표 사이의 거리는 %.1f",dist);
  return 0;
}
