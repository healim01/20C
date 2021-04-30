#include <stdio.h>

int main(void) {
  float m2_area; // 면적 (제곱미터)
  float pyung_area; // 면적 (평수) 
  int count1=0; //소형아파트개수 
  int count2=0; // 중소형 아파트 개수
  int count3=0; //중형아파트개수 
  int count4=0; //대형아파트개수 
  int i;
  
  for (i=0;i<10;i++) {
    printf("아파트의 분양 면적(제곱미터)을 입력하시오. ");
    scanf("%f",&m2_area);
    pyung_area=m2_area/3.305;
    if (pyung_area<15) count1++;
    else if (pyung_area<30) count2++;
    else if (pyung_area<50) count3++;
    else count4++;
    printf("--> 이 아파트의 평형은 %.1f 입니다.",pyung_area);
  }
  printf("\"소형아파트\"의 개수는 %d 입니다.\n",count1);
  printf("\"중소형아파트\"의 개수는 %d 입니다.\n",count2);
  printf("\"중형아파트\"의 개수는 %d 입니다.\n",count3);
  printf("\"대형아파트의 개수는 %d 입니다.\n",count4);
  return 0;
}