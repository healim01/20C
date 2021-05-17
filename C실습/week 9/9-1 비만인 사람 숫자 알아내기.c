#include <stdio.h>

void AskHW(float* h, float *w);

int main(void) {
	float height, weight, bmi;
	int count=0;
	for(int i=0;i<5;i++){
		AskHW(&height, &weight);
		bmi = weight / (height*height);
		if (bmi > 25) count++;
	}
	printf("비만인 사람은 %d명입니다.\n", count);
	return 0;
}

void AskHW(float* h, float *w){
  int num;
  printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오.",num+1);
  scanf("%f %f",h,w);
  *h=*h*0.01;
  num++;
}