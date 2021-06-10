#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int markbingo(int num, int b[25]);
//파라미터 : 선택된 칸번호(num), 빙고매트릭스(b)
//리턴값 : 이미 마크되어 있었음 0, 
//       마크 안되어 마크하였는데 빙고 완성됨 1,  
//       마크 안되어 마크하였는데 빙고는 미완성 -1,  
//수행내용 : 현재의 빙고매트릭스에 선택된 칸번호에 해당되는
//         칸 검사한 후 마크함
void shufflebingo(int b[25]);
//파라미터 : 빙고매트릭스(b)
//리턴값 : 없음
//수행내용 : 현재의 빙고매트릭스의 원소들을 무작위로 섞는다.
//섞는 방법은 임의로 두개의 칸을 골라서, 두 칸의 값을 맞바꾸는 작업을 50번 정도 수행하면 된다.

void printbingo(int b[25]);
// 완성 코드 제시됨

int used[] = {0};

int main(void) {
	int bingo[25]; // 빙고용 매트릭스
	int count=0; // 시도 횟수 
	int number; // 입력받는 번호 
	int check; // 빙고검사결과값 
	int i;

	srand(time(0)); // 랜덤 초기화 

	// 빙고매트릭스 초기화(1부터 25까지 순서대로 넣음)
	// for(i=0;i<25;i++) bingo[i]= i+1;

	shufflebingo(bingo);  // 빙고 매트릭스 섞기 
	printbingo(bingo); // 빙고 매트릭스 출력 
	while(1){
		printf("Enter a number > ");
		scanf("%d", &number);
		if((number<1||number>50)) {
		  printf("EXIT!\n");
		  break;
		}
		else {
			check = markbingo(number, bingo);
			if(check!=0) count++;
			if(check==1) break;
		}
	}
	printbingo(bingo); // 빙고 매트릭스 출력 
	printf("%d번 시도됨!\n", count);
	return 0;

}

int markbingo(int num, int b[25]){
  int mark=0;
  int i, a;
  int ga[5]={0};
  int sa[5]={0};
  int da1=0, da2=0;
  
  
  for (i=0;i<25;i++) {
    if (b[i]==num && b[i]!=0) {
      b[i]=0;
      mark=1;
      break;
    }
  }
  if (mark==0) {
    printf("중복!\n");
    return 0;
  }
  
  for (i=0;i<25;i++) {
    if (i<5 && b[i]==0) ga[0]++;
  	else if (i<10 && b[i]==0) ga[1]++;
  	else if (i<15 && b[i]==0) ga[2]++;
  	else if (i<20 && b[i]==0) ga[3]++;
  	else if (b[i]==0) ga[4]++;
  	a=i%5;
  	
  	if (a==0 && b[i]==0) sa[0]++;
  	else if (a==1 && b[i]==0) sa[1]++;
  	else if (a==2 && b[i]==0) sa[2]++;
    else if (a==3 && b[i]==0) sa[3]++;
    else if (a==4 && b[i]==0) sa[4]++;
    
    if ((i==4 && b[i]==0) || (i==8 && b[i]==0) || (i==12 && b[i]==0) || (i==16 && b[i]==0) || (i==20 && b[i]==0)) da1++;
    if ((i==0 && b[i]==0) || (i==6 && b[i]==0) || (i==12 && b[i]==0) || (i==18 && b[i]==0) || (i==24 && b[i]==0)) da2++;
  }
  
  for (i=0;i<5;i++) {
    if (ga[i]==5) {
      printf("빙고! %d번째 줄\n",i+1);
      return 1;
    }
    if (sa[i]==5) {
      printf("빙고! %d번째 칸\n",i+1);
      return 1;
    }
  }
  
  if (da1==5 || da2==5) {
    printf("빙고! 대각선\n");
    return 1;
  }
  
  return-1;
}

void shufflebingo(int b[25]){
  int num1, num2, num;

  for(int i=0;i<25;i++) {
    b[i] = rand()%50+1;
    used[i] = b[i];
    for (int j=0; j<i; j++) {
      if (b[j] == b[i])i--;
    }
  }
  
  for (int i=0;i<50;i++) {
    num1=rand()%25;
    num2=rand()%25;
    num=b[num1];
    b[num1]=b[num2];
    b[num2]=num;
  }
}

void printbingo(int b[25]){
	int i;
	printf("BINGO MATRIX\n");
	for(i=0;i<25;i++){
		if(i%5==0) 
			printf("--------------------------\n|");
		printf(" %2d |",b[i]);
		if(i%5==4) printf("\n");
	}
	printf("--------------------------\n");
}
