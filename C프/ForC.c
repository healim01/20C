// 섭씨 화씨 변환

#include <stdio.h>

int main(void) {
  float c_degree;
  float f_degree;

  printf("섭씨 온도를 입력 ");
  scanf("%f",&c_degree);
  f_degree=c_degree*1.8+32;
  printf("화씨 온도는 %.1f",f_degree);
  return 0;
}