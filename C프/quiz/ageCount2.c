#include <stdio.h>

int main(void) {
  int adult;
  int child;
  int num;
  int total1,total2, total;

  printf("입력 (성인인원, 소아 청소년 인원) :");
  scanf("%d %d",&adult,&child);

  if (adult+child>10) {
    num=10-adult;
    if (num<0) {
      adult= -num;
      total1=80000;
    }
    else {
      child-=num;
      total1=(adult*8000)+((num)*4000);
      adult=0;
    }
  }
  total2=(adult*10000)+(child*5000);
  total=total1+total2;
  
  printf("출력 결과 : %d",total);
  return 0;
}