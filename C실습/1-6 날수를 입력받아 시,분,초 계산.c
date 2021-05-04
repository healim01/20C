#include <stdio.h>

int main(void) {
  int days; // 입력받은 날 수 
  int hours; // 환산한 시간 
  int minutes; // 환산한 분 
  int seconds; // 환산한 초 

  printf("Days?");
  scanf("%d",&days);
  hours=days*24;
  minutes=days*24*60;
  seconds=days*24*60*60;
  printf("%d days is %d hours.\n",days,hours);
  printf("%d days is %d minutes.\n",days,minutes);
  printf("%d days is %d seconds.\n",days,seconds);
  return 0;
}