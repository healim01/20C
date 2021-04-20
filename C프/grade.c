// 성적 그레이드 

#include <stdio.h>

int main(void) {
  int mid, fin, sub;
  int sum;
  printf("중간 점수 : ");
  scanf("%d",&mid);
  printf("기말 점수 : ");
  scanf("%d",&fin);
  printf("과제 점수 : ");
  scanf("%d",&sub);
  sum=mid*0.35+fin*0.45+sub*0.2;
  printf("학점 : ");
  if (sum>=90) printf("A");
  else if (sum>=80) printf("B");
  else if (sum>=70) printf("C");
  else if (sum>=60) printf("D");
  else printf("F");
  return 0;
}