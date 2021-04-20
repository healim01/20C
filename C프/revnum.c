#include <stdio.h>

int main(void) {
  int num=0, a=0, result=0;

  printf("숫자를 입력하시오 : ");
  scanf("%d",&num);
  while (1) {
    a=num%10;
    num=num/10;
    result=result*10+a;
    if (num==0) break;
  }
  printf("역순으로 변환 : %d",result);
  return 0;
}