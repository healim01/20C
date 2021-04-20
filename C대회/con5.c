// 화살표 찍기

#include <stdio.h>

int main(void) {
  int num[5][2];
  for (int i=0;i<5;i++) {
    scanf("%d %d",&num[i][0],&num[i][1]);
  }
  for (int i=0;i<5;i++) {
    for (int j=0;j<20-num[i][0];j++) printf(" ");
    for (int j=0;j<num[i][0];j++) printf("<");
    for (int j=0;j<num[i][1];j++) printf(">");
    printf("\n");
  }
  return 0;
}

