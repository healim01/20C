#include <stdio.h>
#include <stdlib.h>

struct bmi_struct{
  int height, weight; // 키(cm), 몸무게(kg)
  float bmi; // 비만도
  int bmi_index; // 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

struct bmi_struct* add_bmi();
// 파라미터 : 없음
// 리턴값 : 메모리 할당받아 키, 몸무게, 비만도, 비만도등급이 저장된 구조체 포인터

void eval_bmi(struct bmi_struct* p);
// 파라미터 : 비만도 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 포인터로 키, 몸무게를 가지고 비만도, 비만도등급을 저장

int main(void) {
  struct bmi_struct* one;
	char bmi_string[4][20]={"저체중","정상","과체중","비만"};

	one = add_bmi();

	printf("키: %d ", one->height);
	printf("몸무게: %d ", one->weight);
	printf("비만도: %.1f ", one->bmi);    
  printf("판정결과 : %s\n", bmi_string[one->bmi_index-1]);
	return 0;
}

struct bmi_struct* add_bmi(){
  struct bmi_struct* p = (struct bmi_struct*)malloc(sizeof(struct bmi_struct));
  printf("키와 몸무게를 입력하시오 > ");
  scanf("%d %d", &(p->height), &(p->weight));
  eval_bmi(p);
  return p;
}

void eval_bmi(struct bmi_struct* p){
  p->bmi=(1.0*p->weight)/((p->height*0.01)*(p->height*0.01));
  
  if (p->bmi<18.5) p->bmi_index=1;
  else if (p->bmi<23) p->bmi_index=2;
  else if (p->bmi<25) p->bmi_index=3;
  else p->bmi_index=4;
	
}