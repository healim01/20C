#include <stdio.h>

int power( int n, int a ); 

int main(void) {
  int a,b, num;
  printf("숫자 2개를 입력 ");
  scanf("%d %d", &a,&b);
  num=power(a,b);
  printf("%d의 %d승은 %d",a,b,num);
  return 0;
}

int power( int n, int a ){
  if (a==0) return 1;
  else if (n==a) return n;
  else if (a>1 && a%2==0) return power(n,a/2)*power(n,a/2);
  else return power(n,a/2)*power(n,a/2)*n;
}