#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
	int bingo[5][5]={0}; // 빙고용 매트릭스
	int num1, num2; // 입력받는 행, 열 번호 
	int count=0;
	int i,j,a;
	
	srand(time(0));
	printf("10개의 빙고 칸이 선택되었습니다.\n");
	while (1) {
	  num1=rand()%5;
	  num2=rand()%5;
	 
	  if (bingo[num1][num2]==1) count--;
	  else bingo[num1][num2]=1;
	  count++;
	  if (count>=10) break;
	}
	
	printf("BINGO MATRIX\n");
	printf("---------------------\n");
	for (i=0;i<5;i++) {
	  for (j=0;j<5;j++) printf("| %d ",bingo[i][j]);
	  printf("|\n---------------------\n");
	}


	return 0;
}