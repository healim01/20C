#include <stdio.h>

int main(void) {
  int number; // 입력받은 수
  int count=0; // 입력받은 숫자의 개수
  int totalsum=0; // 총합계
  float average; // 평균 값 
  
  while (1) {
    printf("0초과의 숫자를 입력하세요");
    scanf("%d",&number);
    if (number<=0) break;
    count++;
    totalsum+=number;
  }
  if (totalsum==0) average=0;
  else average=(1.0*totalsum)/count;
  printf("입력한 %d개의 숫자들의 총합계는 %d이고, 평균 값은 %.1f입니다.",count,totalsum,average);
  return 0;
}