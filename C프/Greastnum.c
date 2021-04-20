#include <stdio.h>

int main(void) {
  int num1, num2;
  int f_num, s_num;
  int gong;
  printf("최대공약수 구할 두 정수 : ");
  scanf("%d %d",&num1,&num2);
  if (num1>num2) {
    f_num=num1;
    s_num=num2;
  }
  else {
    f_num=num2;
    s_num=num1;
  }
  while (1) {
    if (f_num%s_num==0) {
      gong=s_num;
      break;
    }
    s_num--;
  }
  printf("%d와 %d의 최대 공약수는 %d이다.",num1,num2,s_num);
  return 0;
}