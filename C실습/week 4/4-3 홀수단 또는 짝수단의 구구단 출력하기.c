#include <stdio.h>

int main(void) {
  int mode; // 출력모드(1: 홀수단, 2: 짝수단) 
  int num;
  int i, j; // 반복문 사용을 위한 변수 
  printf("구구단의 출력모드(1: 홀수단, 2: 짝수단)를 입력하세요.");
  scanf("%d",&mode);
  if (mode==1) num=3;
  else num=2;
  
  for (i=num;i<10;i=i+2) {
    for (j=1;j<10;j++) {
      printf("%d x %d = %d ",i,j,i*j);
      if (j%3==0) printf("\n");
    }
    printf("\n\n");
  }
  return 0;
}