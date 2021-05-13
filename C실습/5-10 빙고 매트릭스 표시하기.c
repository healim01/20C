#include <stdio.h>


int main(void) {
	int bingo[5][5]={0}; // 빙고용 매트릭스
	int number; // 입력받는 행, 열 번호 
	int i,j,a;
	int count=0;
	
	while (1) {
	  printf("Enter a number(1~25) > ");
	  scanf("%d",&number);
	  
	  if (number>25) {
	    printf("EXIT! %d tried!\n",count);
	    break;
	  }
	  
	  if (number<6) i=0;
	  else if (number<11) i=1;
	  else if (number<16) i=2;
	  else if (number<21) i=3;
	  else i=4;
	  a=number%5;
	  if (a==1) j=0;
	  else if (a==2) j=1;
	  else if (a==3) j=2;
	  else if (a==4) j=3;
	  else if (a==0) j=4;
	  
	  if (bingo[i][j]==1) printf("중복!\n");
	  else bingo[i][j]=1;
	  count++;
	}
	printf("BINGO MATRIX\n");
	printf("---------------------\n");
	for (i=0;i<5;i++) {
	  for (j=0;j<5;j++) printf("| %d ",bingo[i][j]);
	  printf("|");
	  printf("\n");
	  printf("---------------------\n");
	}

	return 0;
}

