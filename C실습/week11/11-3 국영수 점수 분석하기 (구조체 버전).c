#include <stdio.h>
struct jumsu_struct{
    int kor, eng, mat;
    int sum;
    float avg;
};
void sumClass(struct jumsu_struct p[], int* sum, float* avg, int i);
void evalStudent(struct jumsu_struct *p, int num);

int main(void) {
  struct jumsu_struct p[5];
  FILE *data;
  int i = 0;
  int sum;
  float avg;
  
  data = fopen("data.txt", "r");
  while(!feof(data)){
    fscanf(data, "%d %d %d", &p[i].kor, &p[i].eng, &p[i].mat);
    i++;
  }
  for (i=0;i<5;i++) printf("%d번 학생 : 국어 %d, 영어 %d, 수학 %d\n",i+1,p[i].kor,p[i].eng,p[i].mat);
  printf("1) 각 과목별 총점과 평균점수\n");
  for(i = 0 ; i < 3 ; i++){
    sumClass(p, &sum, &avg, i);
  }
  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
  for (i=0;i<5;i++) {
    evalStudent(&p[i], i);
  }
  return 0;
}

void sumClass(struct jumsu_struct p[], int* sum, float* avg, int i) {
  if (i==0) {
    for (i=0;i<5;i++) *sum+=p[i].kor;
    printf("국어 ");
  }
  else if (i==1) {
    for (i=0;i<5;i++) *sum+=p[i].eng;
    printf("영어 ");
  }
  else if (i==2) {
    for (i=0;i<5;i++) *sum+=p[i].mat;
    printf("수학 ");
  }
  *avg=*sum/5.0;
  printf("점수의 총점은 %d 평균은 %.1f\n",*sum,*avg);
  *sum=0;
}


void evalStudent(struct jumsu_struct *p, int num) {
  p->sum=p->kor + p->eng + p->mat;
  p->avg=p->sum/3.0;
  printf("%d번 학생의 총점은 %d 평균은 %.1f",num+1,p->sum,p->avg);
  if (p->avg>=90) printf("(등급 A)\n");
  else if (p->avg>=80) printf("(등급 B)\n");
  else if (p->avg>=70) printf("(등급 C)\n");
  else if (p->avg>=60) printf("(등급 D)\n");
  else printf("(등급 F)\n");
}