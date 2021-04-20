#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
1. 10명의 체온을 랜덤으로 만들기 
  1-1. 1000자리로 500 랜덤 하고 0.01 곱하기 

2. 만들어진 체온을 각 구간 (정상, 발열의심, 저체온) 으로 판정

3. 이중 최고 체온과 최저 체온을 구하고 각 몇번째 사람인지 구하기 

4. 주어진 체온의 합을 구하고 평균체온 구하기 

5. 0 일때를 주의해서 확인하기 
*/

int main(void) {
  srand(time(0));
  int num;
	int count1=0, count2=0, count3=0;
	float degree[10]; // 10명의 체온 
	float min=0, max=0, sum=0, avg;
	int min_i=0, max_i=0, i;
	
	for (i=0;i<10;i++) {
	  num=rand()%500+3400;
	  degree[i]=num*0.01;
	}
	printf("체온 목록\n");
	for (i=0;i<10;i++) {
	  printf("%d번 분 - %.2f\n",i+1,degree[i]);
	  sum+=degree[i];
	  if (degree[i]<35.0) count1++;
	  else if (degree[i]<=37.5) count2++;
	  else count3++;
	  
	  if (i==0) {
	    max=degree[i];
	    min=degree[i];
	    max_i=degree[i];
	    min_i=degree[i];
	  }
	  
	  if (degree[i]>max) {
  	    max=degree[i];
  	    max_i=i+1;
  	 }
  	 if (degree[i]<min) {
  	   min=degree[i];
  	   min_i=i+1;
  	 }
  }
  if (sum!=0) avg=sum/10;
  else avg=0;
  
	printf("정상체온 : %d명, 발열의심: %d명, 저체온의심 : %d명\n",count2,count3,count1);
	printf("최고체온 : %.2f ",max);
	if (max_i!=0) printf("(%d번 분)\n",max_i);
	printf("최저체온 : %.2f ",min);
	if (min_i!=0) printf("(%d번 분)\n",min_i);
	printf("평균체온 : %.2f",avg);

  return 0;
}


	
	