#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int jum[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
  char classname[3][20]={"국어","영어","수학"};
  int sum_student[5]={0}; // 학생별 총점
  float average_student[5];  // 학생별 평균
  char grade[5]; // 학생별 등급 
  int sum_class[3]={0}; // 과목별 총점
  float average_class[3]; // 과목별 평균
  int i, j;  // 반복문을 위한 변수 
  
  printf("5명의 학생 점수가 생성되었습니다.\n");
  for (i=0;i<5;i++) {
    for (j=0;j<3;j++) {
      jum[i][j]=rand()%50+50;
      sum_student[i]+=jum[i][j];
      sum_class[j]+=jum[i][j];
      average_class[j]=sum_class[j]/5.0;
    }
    average_student[i]=sum_student[i]/3.0;
    if (average_student[i]>=90) grade[i]='A';
    else if (average_student[i]>=80) grade[i]='B';
    else if (average_student[i]>=70) grade[i]='C';
    else if (average_student[i]>=60) grade[i]='D';
    else grade[i]='F';
  }
  for (i=0;i<5;i++) {
    printf("%d번 학생 : ",i+1);
    for (j=0;j<2;j++) printf("%s %d,",classname[j],jum[i][j]);
    printf("%s %d",classname[2],jum[i][2]);
    printf("\n");
  }
  printf("1) 각 과목별 총점과 평균점수\n");
  for(i=0;i<3;i++) printf("%s 점수의 총점은 %d 평균은 %.1f\n",classname[i],sum_class[i],average_class[i]);
  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
  for (i=0;i<5;i++) printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n",i+1,sum_student[i],average_student[i],grade[i]);


  return 0;
}