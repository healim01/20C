#include <stdio.h>

int Ackermann(int i, int j); 

int main(void) {
  int num;
  for (int i=0;i<=3;i++) {
    for (int j=0;j<=3;j++) {
      num=Ackermann(i,j);
      printf("Ackermann(%d, %d) = %d\n",i,j,num);
    }
  }
  return 0;
}

int Ackermann(int i, int j) {
  if (i==0 && j>=0) return j+1;
  else if (i>0 && j==0) return Ackermann(i-1,1);
  else return Ackermann(i-1,Ackermann(i,j-1));
}