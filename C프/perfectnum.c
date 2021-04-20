/*
1 ~ 100 범위의 정수 중에서 완전수( perfect number)를 모두 찾으시오.
- 완전수 : 어떤 수(n)가, n을 제외한 모든 약수의 합과 같은 경우
Ex)  6 = 1 + 2 + 3 
*/

#include <stdio.h>

int main(void) {
  int i;
  int num, sum;
  for (i=1;i<=100;i++) {
    sum=0;
    num=i-1;
    while (1) {
      if(num==0) break;
      if (i%num==0) sum+=num;
      num--;
    }
    if (sum==i) printf("%d\n",i);
  }
  return 0;
}