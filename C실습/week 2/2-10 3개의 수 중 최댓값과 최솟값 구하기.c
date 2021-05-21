#include <stdio.h>

int main(void) {
  int num1, num2, num3; // 첫 번째 숫자, 두 번째 숫자, 세 번째 숫자 
  int max_num, min_num; // 가장 큰 숫자, 가장 작은 숫자 
  
  printf("첫번째 숫자?");
  scanf("%d",&num1);
  printf("두번째 숫자?");
  scanf("%d",&num2);
  printf("세번째 숫자?");
  scanf("%d",&num3);
  
  if (num1>=num2 && num1>=num3) {
    max_num=num1;
    if (num2>=num3) min_num=num3;
    else min_num=num2;
  }
  else if (num2>=num1 && num2>=num3) {
    max_num=num2;
    if (num1>=num3) min_num=num3;
    else min_num=num1;
  }
  else if (num3>=num1 && num3>=num2) {
    max_num=num3;
    if (num1>=num2) min_num=num2;
    else min_num=num1;
  }
  printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.",max_num,min_num);
  return 0;
}