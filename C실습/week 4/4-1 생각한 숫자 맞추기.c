#include <stdio.h>
/*
50 먼저 묻기
더 크면 1, 더 작으면 2, 맞으면 0 입력 받기

1이면 이전 수보다 크고 최대보다 작은 수 중 하나로 다시 묻기 
최대는 이전에 2이고 가장 작은 거 
출력 숫자는 최대 + 이전 수 /2

2이면 이전 수보다 작고 최소보다 큰 수 중 하나로 다시 묻기
최소는 이전에 1이고 가장 큰 수
출력 숫자는 최소+이전 수/2

0이면 시도 숫자 출력하기 


*/
int main(void) {
  int tried=0;
  int mode;
  int num, max=101, min=1;
  
  while (1) {
    if (tried==0) num=50;
    printf("How about %d? (try more : 1, try less : 2, right : 0)",num);
    scanf("%d",&mode);
    tried++;
    
    if (mode==1) {
      if (num>min) min=num;
      num=(num+max)/2;
    }
    else if (mode==2) {
      if (num<max) max=num;
      num=(num+min)/2;
    }
    else if (mode==0) {
     printf("%d tried.",tried);
     break;
    }
  }
  return 0;
}