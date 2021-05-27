#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(0));
	char code[10][20];
	int i,j;
	int num;
	
	printf("10개의 코드가 생성되었습니다.\n");
	
	for (i=0;i<10;i++) {
	  for (j=0;j<3;j++) code[i][j]=rand()%26+65;
	  code[i][3]='-';
	  code[i][4]=rand()%9+1;
	  for (j=5;j<10;j++) code[i][j]=rand()%10;
	}
	
	for (i=0;i<10;i++) {
	  printf("Code #%d : ",i+1);
	  for (j=0;j<4;j++) printf("%c",code[i][j]);
	  for (j=4;j<10;j++) printf("%d",code[i][j]);
	  printf("\n");
	}


	return 0;
}