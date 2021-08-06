#include <stdio.h>
void MaxMinOfTen(int number[10], int* maxmin[]);

int main(void) {
	int num[10]; // 10개의 숫자를 받을 배열
	int max_num; // 가장 큰 숫자를 리턴 받을 변수, 
	int min_num; // 가장 작은 숫자를 리턴 받을 변수
	int* max_min[2]; // 최대최소값 전달을 위한 포인터배열 

	max_min[0] = &max_num;
	max_min[1] = &min_num;
	for(int i=0;i<10;i++){
		printf("%d번째 숫자를 입력하시오. ", i+1);
		scanf("%d", &num[i]);
	}
	MaxMinOfTen(num, max_min);
	printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", max_num, min_num);
	return 0;
}

void MaxMinOfTen(int number[10], int* maxmin[]){
  int i;
  for (i=0;i<10;i++) {
    if (i==0) {
      *maxmin[0]=number[i];
      *maxmin[1]=number[i];
    }
    if (number[i]>*maxmin[0]) *maxmin[0]=number[i];
    if (number[i]<*maxmin[1]) *maxmin[1]=number[i];
  }
}
