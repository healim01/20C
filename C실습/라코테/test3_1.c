#include <stdio.h>
/*
1. 1번 함수 제작 
 1.1 목록 값에서 시작 값과 끝 값 얻어오기 
 1.2 해당 리스트에서 시작 값과 끝 값 사이에 있는 값 갯수 구하기 
 1.3 해당 갯수 리턴하기
 1.4 다시 갯수변수 초기화 
 
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

int getCount(float list[], int size, float begin, float end);
int getMaxIndex(float list[], int size);
int getMinIndex(float list[], int size);
float getSum(float list[], int size);

int main(void) {
	int persons, count1, count2, count3;
	float degree[20]; // 최대 20명의 체온 
	float min, max, sum, avg;
	int min_i, max_i;
	printf("인원수를 입력하시오 > ");
	scanf("%d", &persons);
	for(int i=0; i<persons; i++){
		printf("%d번 분의 체온을 입력하시오 > ", i+1);
		scanf("%f", &degree[i]);
	}
	
	count1 = getCount(degree, persons, 0.0, 35.0);
	count2 = getCount(degree, persons, 35.0, 37.5);
	count3 = getCount(degree, persons, 37.5, 100.0);
	max_i = getMaxIndex(degree, persons);
	min_i = getMinIndex(degree, persons);
	max = degree[max_i];
	min = degree[min_i];
	sum = getSum(degree, persons);
	avg=sum/persons;
	
	printf("정상체온 : %d명, 발열의심 : %d명, 저체온의심 : %d명\n", count2, count3, count1);
	printf("최고체온 : %.1f (%d번 분)\n", max, max_i+1);
	printf("최저체온 : %.1f (%d번 분)\n", min, min_i+1);
	printf("평균체온 : %.1f\n", avg);
	
  return 0;
}

int getCount(float list[], int size, float begin, float end){
  int count=0;
  
  for (int i=0;i<size;i++) {
    if (list[i]>=begin && list[i]<end) count++;
  }
	return count;
}
int getMaxIndex(float list[], int size){
  int max=0, maxi; 
  for (int i=0;i<size;i++) {
    if (list[i]>max || i==0) {
      max=list[i];
      maxi=i;
    }
  }
	
	return maxi;
}
int getMinIndex(float list[], int size){
  int min=100, mini; 
  for (int i=0;i<size;i++) {
    if (list[i]<min || i==0) {
      min=list[i];
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
