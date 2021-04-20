// max min 비교 + 평균

#include <stdio.h>

int main(void) {
  int num1, num2, num3;
  int max, min;
  float avg;
  printf("첫번째 정수 : ");
  scanf("%d",&num1);
  printf("두번째 정수 : ");
  scanf("%d",&num2);
  printf("세번째 정수 : ");
  scanf("%d",&num3);
  
  if (num1>=num2 && num1>=num3) {
    max=num1;
    if (num2>num3) min=num3;
    else min=num2;
  }
  else if (num2>=num1 || num2>=num3) {
    max=num2;
    if (num1>=num3) min=num3;
    else min=num1;
  }
  else {
    max=num3;
    if (num1>=num2) min=num2;
    else min=num1;
  }
  avg=(num1+num2+num3)/3.0;
  printf("가장 큰 정수는 %d, 가장 작은 정수는 %d\n",max,min);
  printf("평균은 %.1f",avg);
  return 0;
}