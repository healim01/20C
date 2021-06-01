#include <stdio.h>
void MaxMinOfTen(int number[10], int* max, int* min);

int main(void) {
	int num[10]; // 10개의 숫자를 받을 배열
	int max_num; // 가장 큰 숫자를 리턴 받을 변수, 
	int min_num; // 가장 작은 숫자를 리턴 받을 변수
	char file[20]; // 파일 이름
	FILE *data;
	printf("파일 이름을 입력하세요.");
	scanf("%s",file);
	data=fopen(file,"r");
	
	for (int i=0;i<10;i++) {
	  fscanf(data,"%d",&num[i]);
	}
	MaxMinOfTen(num,&max_num,&min_num);

	printf("가장 큰 수는 %d이고, 가장 작은 수는 %d입니다.\n", max_num, min_num);
	fclose(data);
	return 0;
}

void MaxMinOfTen(int number[10], int* max, int* min){
  for (int i=0;i<10;i++) {
    if (number[i]>*max || i==0) *max=number[i];
	  if (number[i]<*min || i==0) *min=number[i];
  }
}
