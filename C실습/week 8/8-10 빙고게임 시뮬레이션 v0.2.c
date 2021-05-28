#include <stdio.h>

int markbingo(int num, int b[5][5]);
//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0, 
//       마크 안되어 마크하였는데 빙고 완성됨 1,  
//       마크 안되어 마크하였는데 빙고는 미완성 -1,  
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는
//         칸 검사한 후 마크함
void printbingo(int b[5][5]);
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음 
//수행내용 : 현재의 빙고매트릭스 내용 표현

int main(void) {
	int bingo[5][5]={0}; // 빙고용 매트릭스
	int count;
	int number;
	int mark;
	
	while (1) {
	  printf("Enter a number(1~25) > ");
	  scanf("%d",&number);
	  
	  if (number>25 || number<1) {
	    printf("EXIT!\n");
	    break;
	  }
	  mark=markbingo(number,bingo);
	  if (mark==0) printf("중복!\n");
	  if (mark==1) {
	    printf("빙고!\n");
	    break;
	  }
	  count++;
	}
	printbingo(bingo);
}

int markbingo(int number, int b[5][5]){
  int a;
  int i,j;
  int sa, ga, da1,da2;
  
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
	  
  if (b[i][j]==1) return 0;
  else {
    b[i][j]=1;
  }
  for (i=0;i<5;i++) {
    sa=1;
    ga=1;
    for (j=0;j<5;j++) {
      if (b[i][j]!=1) sa=0;
      if (b[j][i]!=1) ga=0;
    }
    if (sa==1) return 1;
    if (ga==1) return 1;
  }
  return -1;
}

void printbingo(int b[5][5]) {
  int i,j;
  
  printf("BINGO MATRIX\n");
	printf("---------------------\n");
	for (i=0;i<5;i++) {
	  for (j=0;j<5;j++) printf("| %d ",b[i][j]);
	  printf("|");
	  printf("\n");
	  printf("---------------------\n");
	}
}