#include <stdio.h>

int maxOfTen(int number[10]);
int minOfTen(int number[10]); 

int main(void) {
  int i;
  int num[10];
  int max, min;
  
  for (i=0;i<10;i++) {
    printf("%d번째 숫자를 입력하시오.",i+1);
    scanf("%d",&num[i]);
  }
  max=maxOfTen(num);
  min=minOfTen(num);
  
  printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.",max,min);
  return 0;
}

int maxOfTen(int number[10]) {
  int max;
  int i;
  
  for (i=0;i<10;i++) {
    if (i==0) max=number[0];
    if (number[i]>max) max=number[i];
  }
  return max;
}

int minOfTen(int number[10]) {
  int min;
  int i;
  
  for (i=0;i<10;i++) {
    if (i==0) min=number[0];
    if (number[i]<min) min=number[i];
  }
  return min;
}