#include <stdio.h>

int main(void) {
  int monthdays[12]= {31,28,31,30,31,30,31,31,30,31,30,31}; // 1~12월의 날 수 
  int month, day; // 입력받은 월, 일
  int day_count; // 1년 중 날 수
  int i;  // 반복문을 위한 변수 
  
  printf("Month?");
  scanf("%d",&month);
  printf("Day?");
  scanf("%d",&day);
  if (month>12 || month<1) printf("잘못 입력하셨습니다.");
  else if (day>monthdays[month-1]) printf("잚못 입력하셨습니다.");
  else {
    day_count=day;
    for (i=0;i<month-1;i++) day_count+=monthdays[i];
    printf("이 날짜는 1년 중 %d번째 날에 해당",day_count);
  }

  return 0;
}