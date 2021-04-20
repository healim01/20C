// 사각형 종류 

#include <stdio.h>

int main(void) {
  int n1, n2, n3;
  int num;

  scanf("%d %d %d",&n1,&n2,&n3);

  if (n1 > n2 && n1 > n3) {
    if (n2 < n3) {
      num=n2;
      n2=n3;
      n3=num;
    }
  }
  else if (n2>n1 && n2>n3) {
    num=n1;
    n1=n2;
    n2=num;
    if (n2 < n3) {
      num=n2;
      n2=n3;
      n3=num; 
    }
  }
  else if (n3 >n1 && n3>n2) {
    num=n1;
    n1=n3;
    n3=num;
    if (n2 < n3) {
      num=n2;
      n2=n3;
      n3=num; 
    }
  }

  if (n1>n2+n3) printf("#4.no triangle\n");
  else if (n1*n1==n2*n2+n3*n3) printf("#1.right triangle\n");
  else if (n1*n1<n2*n2+n3*n3) printf("#2.acute triangle\n");
  else if (n1*n1>n2*n2+n3*n3) printf("#3.obtuse triangle\n");
  return 0;
}