#include <stdio.h>

int age_group(int b);

int main(void) {
  int birth_year; // 입력받은 태어난 년도
  int year[100]; // 각 사람들의 생년 (최대 100명)  
  int count_person=0; // 입력된 인원 수
  int count[6]={0}; // 6가지 연령대별 숫자
  int i;
  
  while (1) {
    printf("%d번째 사람의 태어난 년도를 입력하시오.",count_person+1);
    scanf("%d",&birth_year);
    if (birth_year>2020) break;
    year[count_person]=2020-birth_year+1;
    count[age_group(birth_year)]++;
    count_person++;
    if (count_person>=100) break;
  }
  for (i=0;i<count_person;i++) {
    printf("%d번째 사람의 나이는 %d입니다.\n",i+1,year[i]);
  }
  printf("유아는 %d명 입니다.\n어린이는 %d명 입니다.\n",count[0],count[1]);
  printf("청소년은 %d명 입니다.\n청년은 %d명 입니다.\n",count[2],count[3]);
  printf("중년은 %d명 입니다.\n노년은 %d명 입니다.\n",count[4],count[5]);
  
  return 0;
}

int age_group(int b) {
  int age;
  
  age=2020-b+1;
  if (age<7) return 0;
  else if (age<13) return 1;
  else if (age<20) return 2;
  else if (age<30) return 3;
  else if (age<60) return 4;
  else return 5;
}