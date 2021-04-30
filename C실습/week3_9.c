#include <stdio.h>

int main(void) {
  int num1, num2; // 입력받은 두 수
  int i; // 반복문을 위한 변수 

  printf("2개의 숫자를 입력");
  scanf("%d %d",&num1,&num2);
  
  for (i=1;i<=100;i++) {
    if (i%num1==0 || i%num2==0) {
      if (i%num1!=0 || i%num2!=0) printf("%d\n",i);
    }
  }
  return 0;
}