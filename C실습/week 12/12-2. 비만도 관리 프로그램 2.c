#include <stdio.h>
#include <stdlib.h>

struct bmi_struct{
    int height, weight; // 키(cm), 몸무게(kg)
    float bmi; // 비만도
    int bmi_index; // 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

int load_bmi(struct bmi_struct* list[], char* filename);
void eval_bmi(struct bmi_struct* p);

int main(void) {
  struct bmi_struct* bmilist[50];  // 최대 50명의 비만도 데이터
	char bmi_string[4][20]={"저체중","정상","과체중","비만"};
	
	for (int i=0;i<50;i++) bmilist[i]=malloc(sizeof(struct bmi_struct));

	int count = load_bmi(bmilist, "data.txt");

	printf("%d명의 데이터를 읽었습니다.\n",count);// 이 부분의 코드 작성!
	
	for (int i=0;i<count;i++) {
	  printf("%d번 분. 키: %d 몸무게: %d 비만도: %.1f 판정결과: %s\n",i+1,bmilist[i]->height,bmilist[i]->weight,bmilist[i]->bmi,bmi_string[bmilist[i]->bmi_index-1]);
	}

	return 0;
}

int load_bmi(struct bmi_struct* list[], char* filename){
  int k=0;
  FILE * file1;
  file1=fopen( filename , "r");
  for (int i=0;i<50;i++) {
    fscanf(file1,"%d %d",&(list[i]->height), &(list[i]->weight));
    eval_bmi(list[i]);
    if (feof(file1)) break;
    k++;
  }
  
  fclose(file1);
	return k;
}

void eval_bmi(struct bmi_struct* p){
  p->bmi=(1.0*p->weight)/((p->height*0.01)*(p->height*0.01));
  
  if (p->bmi<18.5) p->bmi_index=1;
  else if (p->bmi<23) p->bmi_index=2;
  else if (p->bmi<25) p->bmi_index=3;
  else p->bmi_index=4;
	
}