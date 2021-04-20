// 윤년 판단

#include <stdio.h>

int main(void) {
  int year;
  int ly;
  printf("year : ");
  scanf("%d",&year);
  if (year%4==0) {
    if (year%100==0) {
      if (year%400==0) ly=1;
      else ly=0;
    }
    else ly=1;
  }
  else ly=0;
  if (ly==1) printf("윤년입니다.");
  else printf("윤년이 아닙니다.");
  return 0;
}