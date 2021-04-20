#include <stdio.h>

int main(void) {
  int day, num;
  int i;
  int count;

  printf("1일의 요일 : ( 0: Sun,  1:Mon, 2:Tue, 3:Wed, 4:Thu, 5:Fri, 6:Sat) : ");
  scanf("%d",&day);
  printf("Number of days : ");
  scanf("%d",&num);
  printf("Sun    Mon    Tue    Wed    Thu   Fri    Sat\n");
  for (i=0;i<day;i++) {
    printf("       ");
    count++;
  }
  for (i=1;i<=num;i++) {
    if (i<10) printf("%d      ",i);
    else printf("%d     ",i);
    count++;
    if (count%7==0) printf("\n");
  }

  return 0;
}