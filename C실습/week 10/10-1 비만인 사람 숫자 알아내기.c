#include <stdio.h>

float evalbmi(int h, int w);

int main(void) {
	int height, weight;
	float bmi;
	int count=0, i;
	FILE * file1;
	file1=fopen("data.txt","r");
	for (i=0;i<5;i++) {
	 fscanf(file1,"%d %d",&height,&weight);
	 printf("%d번째 사람의 신장(cm)과 체중(kg) : %d %d\n",i+1,height,weight);
	 bmi=evalbmi(height, weight);
	 if (bmi>=25) count++;
	}
	
	printf("비만인 사람은 %d명입니다.\n", count);
	fclose(file1);
	return 0;
}

float evalbmi(int h, int w){
  int bmi;
  bmi=(w)/((h*0.01)*(h*0.01));
  
  return bmi;
}