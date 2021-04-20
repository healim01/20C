// 가게 물건 가격 측정

#include <stdio.h>

int main(void) {
  int num;
  char name[20][20];
  int count[20];
  int price[20];
  int sum=0;

  scanf("%d",&num);
  for (int i=0;i<num;i++) {
    scanf("%s %d %d",name[i],&count[i],&price[i]);
    sum+=count[i]*price[i];
  }
  printf("Total : %d\n",sum);
  return 0;
}