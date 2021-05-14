#include <stdio.h>

int main(void) {
  int money;
  int ohund, hund, oten, ten, one;
  int total;

  printf("입력 :");
  scanf("%d",&money);
  ohund=money/500;
  hund=(money-ohund*500)/100;
  oten=(money-ohund*500-hund*100)/50;
  ten=(money-ohund*500-hund*100-oten*50)/10;
  one=(money-ohund*500-hund*100-oten*50-ten*10);

  total=ohund+hund+oten+ten+one;
  printf("출력 : %d",total);
  return 0;
}