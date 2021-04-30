#include <stdio.h>

int main(void) {
  int number; 
  int totalsum=0; 
  int i; 

  printf("숫자를 입력하세요.");
  scanf("%d",&number);
  if (number<=1) printf("잘못 입력하였습니다.");
  else {
    for (i=1;i<=number;i++) {
      totalsum+=i;
    }
    printf("1부터 입력한 숫자까지의 모든 정수를 더한 값은 %d 입니다.",totalsum);
  }
  

  return 0;
}