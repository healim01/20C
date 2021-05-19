#include <stdio.h>

void PrintChar(int size, char ch);

int main(void) {
  char mon;
  int num[10];
  int i;
  
  printf("사용할 문자?");
  scanf("%c",&mon);
  printf("숫자 10개?");
  for (i=0;i<10;i++) scanf("%d",&num[i]);
  for (i=0;i<10;i++) PrintChar(num[i],mon);
  return 0;
}

void PrintChar(int size, char ch) {
  int i;
  for (i=0;i<size;i++) printf("%c",ch);
  printf("\n");
  
}