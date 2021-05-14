#include <stdio.h>

int main(void) {
  int count=0;
  int a[10]={3,21,14,16,37,15,22,33,19,8};
  int b[10]={17,37,14,44,19,31,22,16,21,8};

  for (int i=0;i<10;i++) {
    for (int j=0;j<10;j++) {
      if (a[i]==b[j]) {
        count++;
        break;
      }
    }
  }
  printf("출력 결과 : %d",10-count);
  return 0;
}