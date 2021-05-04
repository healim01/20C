#include <stdio.h>

int main(void) {
  int month, day; // 월, 일
  int day_count; // 1년 중 날 수 
  
  printf("Month?");
  scanf("%d",&month);
  printf("Day?");
  scanf("%d",&day);
  if (month<1 || month>12) printf("잘못 입력하셨습니다.");
  else if (day>31) printf("잘못 입력하셨습니다.");
  else if (month==2) {
    if (day>28) printf("잘못 입력하셨습니다.");
  }
  else if (month==4 || month==6 || month==9 || month==11) {
    if (day>30) printf("잘못 입력하셨습니다.");
  }
  else {
    day_count=day;
    if (month==1) day_count=day_count;
    else if (month==2) day_count+=31;
    else if (month==3) day_count=day_count+31+28;
    else if (month==4) day_count=day_count+31+28+31;
    else if (month==5) day_count=day_count+31+28+31+30;
    else if (month==6) day_count=day_count+31+28+31+30+31;
    else if (month==7) day_count=day_count+31+28+31+30+31+30;
    else if (month==8) day_count=day_count+31+28+31+30+31+30+31;
    else if (month==9) day_count=day_count+31+28+31+30+31+30+31+31;
    else if (month==10) day_count=day_count+31+28+31+30+31+30+31+31+30;
    else if (month==11) day_count=day_count+31+28+31+30+31+30+31+31+30+31;
    else if (month==12) day_count=day_count+31+28+31+30+31+30+31+31+30+31+30;
    printf("이 날짜는 1년 중 %d번째 날에 해당됩니다.",day_count);
  }