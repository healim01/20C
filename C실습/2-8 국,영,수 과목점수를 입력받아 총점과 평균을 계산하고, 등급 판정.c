#include <stdio.h>

int main(void) {
  int kor, eng, math; // 국어점수, 영어점수, 수학점수
  int total; // 총점
  float average;  // 평균점수
  printf("국어 점수를 입력하세요");
  scanf("%d",&kor);
  printf("영어 점수를 입력하세요");
  scanf("%d",&eng);
  printf("수학 점수를 입력하세요");
  scanf("%d",&math);
  total=kor+eng+math;
  average=total/3.0;
  printf("입력하신 점수의 총점은 %d 이고,\n평균은 %.1f 입니다.\n",total,average);
  if (kor>=90) printf("국어점수가 우수합니다.\n");
  if (eng>=90) printf("영어점수가 우수합니다.\n");
  if (eng>=90) printf("수학점수가 우수합니다.\n");

  return 0;
}