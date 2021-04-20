#include <stdio.h>

int main(void) {
  int year;
  int month;
  int day;
  int ly;

  printf("날짜 입력 : ");
  scanf("%d %d %d",&year,&month,&day);

  if (year%4==0) {
    if (year%100==0) {
      if (year%400==0) ly=1;
      else ly=0;
    }
    else ly=1;
  }
  else ly=0;
  if (month==2) {
    if (day==28 && ly==0) {
      month++;
      day=1;
    }
    else day++;
  }
  else if (month==4 || month==6 || month==9 || month==11) {
    if (day==30) {
      month++;
      day=1;
    }
    else day++;
  }
  else {
    if (day==31) {
      month++;
      day=1;
    }
    else day++;
  }
  if (month==13) {
    year++;
    month=1;
  }
  printf("다음 날 : %d %d %d",year,month,day);
  return 0;
}