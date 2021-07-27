#include <stdio.h>

int fibonacci(int n); 

int main(void) {
  float a,b;
  int num1, num2, num3, i=1;
  float result1, result2;
  
  while (1) {
    
    if (i==1) num1=fibonacci(i);
    else num1=fibonacci(i-1);
    num2=fibonacci(i);
    num3=fibonacci(i+1);
    
    result1=(float) num2/num1;
    result2=(float) num3/num2;
    
    if (result2>=result1) {
      b=result2;
      a=result1;
    }
    else {
      b=result1;
      a=result2;
    }
    printf("%d번째 비율 (%d / %d) : %f\n",i,num3,num2,result2);
    if (i!=1 && b-a < 0.000001) break;
    i++;
  }
  return 0;
}

int fibonacci(int n) {
  if (n==1 || n==2 ) return 1;
  else return fibonacci(n-1)+fibonacci(n-2);
}
