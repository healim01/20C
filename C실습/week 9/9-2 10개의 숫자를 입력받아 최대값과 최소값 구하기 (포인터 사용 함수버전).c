#include <stdio.h>
void MaxMinOfTen(int number[10], int* max, int* min);

int main(void) {
	int num[10]; // 10개의 숫자를 받을 배열
	int max_num; // 가장 큰 숫자를 리턴 받을 변수, 
	int min_num; // 가장 작은 숫자를 리턴 받을 변수

	for(int i=0;i<10;i++){
		printf("%d번째 숫자를 입력하시오. ", i+1);
		scanf("%d", &num[i]);
	}
	MaxMinOfTen(num, &max_num, &min_num);
	printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", max_num, min_num);
	return 0;
}

void MaxMinOfTen(int number[10], int* max, int* min){
  int i;
  for (i=0;i<10;i++) {
    if (i==0) {
      *max=number[i];
      *min=number[i];
    }
    if (number[i]>*max) *max=number[i];
    if (number[i]<*min) *min=number[i];
  }
	
}
