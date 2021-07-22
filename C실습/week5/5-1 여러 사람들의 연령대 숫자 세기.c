#include <stdio.h>

int main(void) {
  int birth_year; // 입력받은 태어난 년도
  int year[100]; // 각 사람들의 생년 (최대 100명) 
  int count_person=0; // 입력된 인원 수
  int count_baby=0; // 유아 수
  int count_child=0; // 어린이 수
  int count_youth=0; // 청소년 수
  int count_young=0; // 청년 수
  int count_adult=0; // 중년 수
  int count_old=0; // 노년 수
  int age;
  int i; // 반복문을 위한 변수 
  
  while (1) {
    printf("%d번째 사람의 태어난 년도를 입력하시오.",count_person+1);
    scanf("%d",&birth_year);
    age=2020-birth_year+1;
    if (birth_year>2020) break;
    year[count_person]=age;
    
    if (age<7) count_baby++;
    else if (age<13) count_child++;
    else if (age<20) count_youth++;
    else if (age<30) count_young++;
    else if (age<60) count_adult++;
    else count_old++;
    count_person++;
    if (count_person>=100) break;
  }
  
  for (i=0;i<count_person;i++) {
    printf("%d번째 사람의 나이는 %d입니다.\n",i+1,year[i]);
  }
  printf("유아는 %d명입니다.\n어린이는 %d명입니다.\n청소년은 %d명입니다.\n",count_baby,count_child,count_youth);
  printf("청년은 %d명입니다.\n중년은 %d명입니다.\n노년은 %d명입니다.\n",count_young,count_adult,count_old);
  return 0;
}