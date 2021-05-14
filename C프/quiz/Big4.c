#include <stdio.h>

int main(void) {
  int count=1;
  int a[10]={1,3,5,7,9,10,8,6,4,2};

  for (int i=0;i<10;i++) {
    for (int j=0;j<10;j++) {
      if(a[j]>a[i]) count++;
    }
    if (count==4) {
      printf("출력 결과 : %d",a[i]);
      break;
    }
    count=1;
  }
  return 0;
}