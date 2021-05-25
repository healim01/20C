#include <stdio.h>

int main(void) {
  int number[10]; // 사용자가 입력한 숫자 10개
  int count;  // 현재까지 입력된 숫자의 갯수(0~10)
  int i; // 반복문을 위한 변수 
  printf("1부터 100사이의 숫자를 입력하시오.\n");
  
  while (1) {
    printf("%d번째 숫자를 입력하시오.",count+1);
    scanf("%d",&number[count]);
    for (i=0;i<count;i++) {
      if (number[count]==number[i]) {
        printf("잘못 입력하였습니다. 다시 입력하세요.\n");
        count--;
      }
    }
    count++;
    if (count==10) break;
  }
  for (i=0;i<10;i++) printf("%d번째 숫자는 %d입니다.\n",i+1,number[i]);
  return 0;
}