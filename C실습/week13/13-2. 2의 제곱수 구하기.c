#include <stdio.h>

int poweroftwo(int n);

int main(void) {
  int num, result;
  while (1) {
    printf("숫자 입력 ( 0 종료 ) : ");
    scanf("%d",&num);
    if (num==0) break;
    result=poweroftwo(num);
    printf("2의 %d승은 %d\n",num,result);
  }
  return 0;
}

int poweroftwo(int n) {
  if (n==0) return 1;
  else return 2*poweroftwo(n-1);
}