// 한동대에 1학년 비율

#include <stdio.h>

int main(void) {
  int hgu, gls;

  scanf("%d %d",&hgu, &gls);
  printf("Ratio : %.1f%%",(float)gls/hgu*100);
  return 0;
}