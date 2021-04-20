#include <stdio.h>
/*
1. 1번 함수 제작 
 1.1 전달받은 파일 degree.txt 열기
 1.2 파일에서 온도 읽어오기 
 1.3 해당 온도로 data 배열 만들기 
 1.4 배열 리턴하기 
 
2. 2번 함수 제작 
 2.1 주어진 시작값과 끝 값 사이에 들어가는 온도 몇개인지 구하기 
 2.2 해당 갯수 리턴하기 
 
3. 3번 함수 제작 
 3.1 목록과 갯수 받기 
 3.2 해당 배열 중 가장 큰 값 찾기 
 3.3 해당 인덱스 값 찾아서 리턴하기 
 
4. 4번 함수 제작 
 4.1 목록과 갯수 받아오기 
 4.2 해당 배열 중 가장 작은 값 찾기 
 4.3 해당 인덱스 값 찾아서 리턴하기 
 
5. 5번 함수 제작 
 5.1 받은 배열의 모든 온도 더하기 
 5.2 총합 리턴하기 


*/
int getCount(float list[], int size, float begin, float end);
int getMaxIndex(float list[], int size);
int getMinIndex(float list[], int size);
float getSum(float list[], int size);
int loadData(char* filename, float data[]);

int main(void) {
	int persons, count1, count2, count3;
	float degree[20]; // 최대 20명의 체온 
	float min, max, sum, avg;
	int min_i, max_i;
	persons = loadData("degree.txt", degree);

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

int loadData(char* filename, float data[]){
  int i=0;
  FILE * file;
  file=fopen( filename ,"r");
  
  for (int k=0;k<20;k++) {
    fscanf(file,"%f",&data[i]);
    if (feof(file)) break;
    i++;
  }
  printf("%d명의 체온을 읽었습니다.\n",i);
	return i;
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
