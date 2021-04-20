// 구구단

#include <stdio.h>

int main(void) {
  int i;
  int dan;
  printf("Select a column of multiplication table : ");
  scanf("%d",&dan);
  for (i=1;i<10;i++) printf("%d * %d = %d\n",dan,i,dan*i); 
  return 0;
}