#include <stdio.h>

void PrintCharWithBlank(int blanks, int size, char ch);

int main(void) {
  char mon;
  int blanks;
  int size;
  
  printf("사용할 문자?");
  scanf("%c",&mon);
  printf("높이와 여백의 크기?");
  scanf("%d %d",&size,&blanks);
  PrintCharWithBlank(blanks,size,mon);
  
  return 0;
}

void PrintCharWithBlank(int blanks, int size, char ch) {
  int i,j;
  int num;
  
  for (i=0;i<size;i++) {
    num=size-i-1;
    for (j=0;j<blanks;j++) printf(" ");
    for (j=0;j<num;j++) printf(" ");
    for (j=0;j<=i;j++) printf("%c",ch);
    printf("\n");
  }
  
}