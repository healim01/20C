#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int num[100];
  int count=0;
  int i,j;
  int size, sizenum;
  
  srand(time(0));
  printf("Enter size >>");
  scanf("%d",&size);
  
  while (1) {
    if (size==0) break;
    num[count]=rand()%100+1;
    for (i=0;i<count;i++) {
      if (num[count]==num[i]) count--;
    }
    if (count==size-1) break;
    count++;
  }
  
  count=0;
  for (i=1;i<=100;i++) {
    sizenum=0;
    for (j=0;j<size;j++) {
      if (i==num[j]) {
        printf("@");
        if (i%10==0) printf("\n");
        sizenum=1;
      }
    }
    if (sizenum==1) continue;
    printf("+");
    if(i%10==0) printf("\n");
  }

	return 0;
}