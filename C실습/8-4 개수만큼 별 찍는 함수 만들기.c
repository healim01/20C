#include <stdio.h>

void PrintStar(int size);

int main(void) {
  int num[10];
  int i;
  
  printf("숫자 10개를 입력");
  for (i=0;i<10;i++) scanf("%d",&num[i]);
  for (i=0;i<10;i++) PrintStar(num[i]);
  return 0;
}

void PrintStar(int size) {
  int i;
  for (i=0;i<size;i++) printf("*");
  printf("\n");
}