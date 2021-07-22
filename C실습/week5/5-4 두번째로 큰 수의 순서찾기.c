#include <stdio.h>

int main(void) {
  int num[10]; // 10개의 숫자
  int first;  // 첫 번째로 큰 수
  int second; // 두 번째로 큰 수
  int first_index;
  int second_max_index; // 두 번째로 큰 수의 인덱스 
  int i;  // 반복문을 위한 변수 
  
  for (i=0;i<10;i++) {
    printf("%d번째 수를 입력하시오.",i+1);
    scanf("%d",&num[i]);
    if (i==1) {
      if (num[1]>num[0]) {
        first=num[1];
        second=num[0];
        first_index=2;
        second_max_index=1;
      }
      else {
        first=num[0];
        second=num[1];
        first_index=1;
        second_max_index=2;
      }
    }
    if (num[i]>first) {
      second=first;
      second_max_index=first_index;
      first=num[i];
      first_index=i+1;
    }
    else if (num[i]<first && num[i]>second) {
      second=num[i];
      second_max_index=i+1;
    }
  }
  printf("두번째로 큰 수는 %d번째 수 %d입니다.",second_max_index,second);

  return 0;
}