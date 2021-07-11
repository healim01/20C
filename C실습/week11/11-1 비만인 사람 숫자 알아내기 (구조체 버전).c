#include <stdio.h>
struct bmi_struct{
    int height, weight; // 키(cm), 몸무게(kg)
    float bmi; // 비만도
    int bmi_index; // 1,2,3,4
};

int main(void) {
  FILE * data;
  data=fopen("data.txt","r");
  struct bmi_struct person[5];
  
  for (int i=0;i<5;i++) {
    printf("%d번째 사람의 신장(cm)과 체중(kg) :",i+1);
    fscanf(data,"%d %d",&person[i].height,&person[i].weight);

    printf("%d %d\n",person[i].height,person[i].weight);
    
    person[i].bmi=(person[i].weight)/((person[i].height*0.01)*(person[i].height*0.01));
    if (person[i].bmi>=25) person[0].bmi_index++;
  }
  printf("비만인 사람은 %d명입니다.\n",person[0].bmi_index);
  return 0;
}