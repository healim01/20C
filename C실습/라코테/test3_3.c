#include <stdio.h>
/*
1. 1번 함수 제작 
 1.1 값 목록과 그 목록이 해당 구간 안에 몇명 있는가 구하기 
 1.2 해당 구간에 갯수 구하고 저장하기 

2. 2번 함수 제작 
 2.1 가장 큰 값 찾기
 2.2 큰 값의 인덱스 값 찾아 리턴하기 
 
3. 3번 함수 제작 
 3.1 가장 작은 값 찾기 
 3.2 가장 작은 값의 인덱스 값 찾아서 리턴하기 
 
4. 4번 함수 제작 
 4.1 모든 목록 값과 갯수 가져오기 
 4.2 목록의 총합 구하기 
 4.3 총합 리턴하기 

  

*/

void makeCount(float list[], int size, int* count, float* range, int csize);
int findMax(float list[], int size, float* max);
int findMin(float list[], int size, float* min);
float getSum(float list[], int size);

int main(void) {
	int persons;
	int counts[3]={0}; // 3구간의 카운트값 
	float ranges[4]={0.0, 35.0, 37.5, 100.0}; // 3구간의 기준 숫자 4개
	float degree[20]; // 최대 20명의 체온 
	float min, max, sum, avg;
	int min_i, max_i;
	printf("인원수를 입력하시오 > ");
	scanf("%d", &persons);
	for(int i=0; i<persons; i++){
		printf("%d번 분의 체온을 입력하시오 > ", i+1);
		scanf("%f", &degree[i]);
	}
	
	makeCount(degree, persons, counts, ranges, 3);
	max_i = findMax(degree, persons, &max);
	min_i = findMin(degree, persons, &min);
	sum = getSum(degree, persons);
	avg=sum/persons;
	
	printf("정상체온 : %d명, 발열의심 : %d명, 저체온의심 : %d명\n", counts[1], counts[2], counts[0]);
	printf("최고체온 : %.1f (%d번 분)\n", max, max_i+1);
	printf("최저체온 : %.1f (%d번 분)\n", min, min_i+1);
	printf("평균체온 : %.1f\n", avg);
	
  return 0;
}

void makeCount(float list[], int size, int* count, float* range, int csize){
  for (int i=0;i<csize;i++) {
    for (int j=0;j<size;j++) {
      if (list[j]>= range[i] && list[j] < range[i+1]) count[i]++;
    }
  }
}
int findMax(float list[], int size, float* max){
  int maxi;
  for (int i=0;i<size;i++) {
    if (list[i]>*max || i==0) {
      *max=list[i];
      maxi=i;
    }
  }
	
	return maxi;
}
int findMin(float list[], int size, float* min){
  int mini;
  for (int i=0;i<size;i++) {
    if (list[i]<*min || i==0) {
      *min=list[i];
      mini=i;
    }
  }
	
	return mini;
}
float getSum(float list[], int size){
  float sum;
  for (int i=0;i<size;i++) {
    sum+=list[i];
  }
	return sum;
}
