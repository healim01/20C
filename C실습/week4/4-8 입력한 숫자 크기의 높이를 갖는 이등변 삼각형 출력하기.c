#include <stdio.h>

int main(void) {
  int height; // 입력받은 높이
  int blank;
  int i, j; // 반복문 사용을 위한 변수
  
	printf("height? ");
	scanf("%d",&height);
	blank=height-1;
	for (i=0;i<height;i++) {
	  for (j=0;j<blank;j++) printf(" ");
	  for (j=0;j<(2*i+1);j++) printf("*");
	  blank--;
	  printf("\n");
	}
	return 0;
}