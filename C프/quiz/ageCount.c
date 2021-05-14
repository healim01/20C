#include <stdio.h>

int main(void) {
  int adult;
  int child;
  int total;

  printf("입력 (성인인원, 소아 청소년 인원) :");
  scanf("%d %d",&adult,&child);

  total=(adult*10000)+(child*5000);
  if (adult+child>=10) total*=0.8;
  
  printf("출력 결과 : %d",total);
  return 0;
}