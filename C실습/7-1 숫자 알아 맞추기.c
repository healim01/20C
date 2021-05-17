#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int num, answer;
  int count=0;

  srand(time(0));
  answer=rand()%100+1;
  
  while (1) {
    count++;
    printf("1부터 100까지의 숫자 하나를 맞춰보세요");
    scanf("%d",&num);
    if (num>answer) printf("좀 더 작은 수입니다.\n");
    else if (num<answer) printf("좀 더 큰 수입니다.\n");
    else if (num==answer) break;
  }
  printf("%d 번만에 숫자를 맞추셨습니다.",count);
  
  
  return 0;
}