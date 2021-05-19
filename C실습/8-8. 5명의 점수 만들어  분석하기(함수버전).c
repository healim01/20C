#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int classsum(int s[5][3], int classnum);
// 파라미터 : 점수배열(s)과 과목번호(0,1,2) 
// 리턴값 : 해당 과목의 총점
int studentsum(int s[5][3], int classnum);
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 총점
char studentgrade(float s, int classnum);
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 등급 ('A','B','C','D','F')

int main(void) {
  srand(time(0));
  int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
  char classname[3][20]={"국어","영어","수학"};
  int sum_student[5]; // 학생별 총점
  float average_student[5];  // 학생별 평균
  char grade[5]; // 학생별 등급 
  int sum_class[3]; // 과목별 총점
  float average_class[3]; // 과목별 평균
  int i, j;  // 반복문을 위한 변수 
  
  printf("5명의 학생 점수가 생성되었습니다.\n");
  for (i=0;i<5;i++) {
    for (j=0;j<3;j++) jumsu[i][j]=rand()%50+50;
  }
  for (i=0;i<5;i++) {
    printf("%d번 학생 :",i+1);
    for (j=0;j<3;j++) printf("%s %d ",classname[j],jumsu[i][j]);
    printf("\n");
  }
  classsum(jumsu,5);
  studentsum(jumsu,3);


  return 0;
}

int classsum(int s[5][3], int classnum){
  char classname[3][20]={"국어","영어","수학"};
  int sum_class[3]={0}; // 과목별 총점
  float average_class[3]; // 과목별 평균
  int i,j;
  
  for (i=0;i<3;i++) {
    for (j=0;j<5;j++) sum_class[i]+=s[j][i];
    average_class[i]=sum_class[i]/classnum;
  }
  printf("1) 각 과목별 총점과 평균점수\n");
  for (i=0;i<3;i++) {
    printf("%s 점수의 총점은 %d 평균은 %.1f\n",classname[i],sum_class[i],average_class[i]);
  }
  return 0;
}
int studentsum(int s[5][3], int classnum){
  char classname[3][20]={"국어","영어","수학"};
  int sum_student[5]={0}; // 학생별 총점
  float average_student[5];  // 학생별 평균
  int i,j;
  
  for (i=0;i<5;i++) {
    for (j=0;j<3;j++) sum_student[i]+=s[i][j];
  }
  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
  for (i=0;i<5;i++) {
    average_student[i]=sum_student[i]/classnum;
    printf("%d번 학생의 총점은 %d 평균은 %.1f ",i+1,sum_student[i],average_student[i]);
    studentgrade(average_student[i], 3);
  }
  return 0;
}
char studentgrade(float s, int classnum) {
  int i;
  if (s>=90) printf("(등급 A)\n");
  else if (s>=80) printf("(등급 B)\n");
  else if (s>=70) printf("(등급 C)\n");
  else if (s>=60) printf("(등급 D)\n");
  else printf("(등급 F)\n");
  return 0;
}