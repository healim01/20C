#include <stdio.h>

int markbingo(int num, int b[25]);
//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0, 
//       마크 안되어 마크하였는데 빙고 완성됨 1,  
//       마크 안되어 마크하였는데 빙고는 미완성 -1,  
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는
//         칸 검사한 후 마크함
void printbingo(int b[25]);
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음 
//수행내용 : 현재의 빙고매트릭스 내용 표현

int main(void) {
	int bingo[25]={0}; // 빙고용 매트릭스
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

int markbingo(int num, int b[25]){
  int a,c;
  int i,j;
  int sa1=0,sa2=0,sa3=0,sa4=0,sa5=0;
  int ga1=0,ga2=0,ga3=0,ga4=0,ga5=0;
  
	  
  if (b[num-1]==1) return 0;
  else {
    b[num-1]=1;
  }
  
  for (i=0;i<25;i++) {
    if (i<5 && b[i]==1 ) ga1++;
  	else if (i<10 && b[i]==1 ) ga2++;
  	else if (i<15 && b[i]==1 ) ga3++;
  	else if (i<20 && b[i]==1 ) ga4++;
  	else if (b[i]==1) ga5++;
  	a=i%5;
  	
  	if (a==0 && b[i]==1) sa1++;
  	else if (a==1 && b[i]==1) sa2++;
  	else if (a==2 && b[i]==1) sa3++;
    else if (a==3 && b[i]==1) sa4++;
    else if (a==4 && b[i]==1 ) sa5++;
  }

  if (ga1==5 || ga2==5 || ga3==5 || ga4==5 || ga5==5) return 1;
  if (sa1==5 || sa2==5 || sa3==5 || sa4==5 || sa5==5) return 1;
  
  return -1;
	
}

void printbingo(int b[25]){
  int i,j;
  
  printf("BINGO MATRIX\n");
	printf("---------------------\n");
	for (i=0;i<25;i++) {
	  printf("| %d ",b[i]);
	  if (i%5==4) {
	    printf("|");
	    printf("\n");
	    printf("---------------------\n");
	  }
	}
}
