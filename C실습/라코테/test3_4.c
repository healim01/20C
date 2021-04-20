#include <stdio.h>
/*

1. makeValue 함수 제작 

 1.1 해당 배열과 구조체에 들어 있는 값 구하기 
 
 1.2 해당 값 중 정해진 구간에 들어가 있는 값 구하기 
 
 1.3 최고 온도 구하고 해당 값 인덱스 구하기 
 
 1.4 최저 온도 구하고 해당 값 인덱스 구하기 
 
 1.5 총점 구하고 평균 구하기 
 
 1.6 구한 값 출력 하기 

*/

struct st_covid{
	float degree[20]; // 최대 20명의 체온 
	int persons;
	int counts[3];  // 3구간의 카운트값 
	float sum, avg; // 총합, 평균 
	int min_i, max_i; // 최소값, 최대값의 인덱스 
};

void makeValue(struct st_covid* data, float* range);

int main(void) {
	struct st_covid mydata;
	float ranges[4]={0.0, 35.0, 37.5, 100.0}; // 3구간의 기준 숫자 4개

	printf("인원수를 입력하시오 > ");
	scanf("%d", &mydata.persons);
	for(int i=0; i<mydata.persons; i++){
		printf("%d번 분의 체온을 입력하시오 > ", i+1);
		scanf("%f", &mydata.degree[i]);
	}

	makeValue(&mydata, ranges);

	printf("정상체온 : %d명, 발열의심 : %d명, 저체온의심 : %d명\n", mydata.counts[1], mydata.counts[2], mydata.counts[0]);
	printf("최고체온 : %.1f (%d번 분)\n", mydata.degree[mydata.max_i], mydata.max_i+1);
	printf("최저체온 : %.1f (%d번 분)\n", mydata.degree[mydata.min_i], mydata.min_i+1);
	printf("평균체온 : %.1f\n", mydata.avg);
	
  return 0;
}

void makeValue(struct st_covid* data, float* range) {
  int i=0 ;
  int max, min;
  int maxi, mini;
  float sum;
  int count[10];
  for (int i=0;i<3;i++) data->counts[i]=0;
  
  for (int i=0;i<data->persons;i++) {
    for (int j=0;j<3;j++) {
      if (data->degree[i] >= range[j] && data->degree[i] < range[j+1]) data->counts[j]++;
    }
  }
  

  for (int i=0;i<data->persons;i++) {
    if ( data->degree[i] > max || i==0) {
      max=data->degree[i];
      data->max_i=i;
    }
    if (data->degree[i]<min || i==0) {
      min=data->degree[i];
      data->min_i=i;
    }
    data->sum+=data->degree[i];
  }
  data->avg=(1.0*data->sum)/data->persons;
}

