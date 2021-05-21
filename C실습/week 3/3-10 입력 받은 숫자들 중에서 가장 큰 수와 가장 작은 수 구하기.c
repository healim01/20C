#include <stdio.h>

int main(void) {
  int number; // 입력받은 수 
  int max_num=0, min_num=100; // 가장 큰 숫자, 가장 작은 숫자 
  
  while (1) {
    printf("0부터 100 사이의 숫자를 입력");
    scanf("%d",&number);
    if (number<0 || number>100) break;
    if (number>max_num) max_num=number;
    if (number<min_num) min_num=number;
  }

  printf("입력된 숫자들 중 가장 큰수는 %d이고,\n가장 작은 수는 %d 입니다.",max_num,min_num);
  return 0;
}