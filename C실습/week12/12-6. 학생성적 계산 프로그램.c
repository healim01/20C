#include <stdio.h>
#include <stdlib.h>

struct st_jumsu{ 
     int kor; 
     int eng;
     int mat;
     int sum;
     float average; 
}; 
void save_jumsu(struct st_jumsu* list[], int count);

int main(void) {
  FILE * file1;
  file1=fopen("jumsu.txt","w");
  struct st_jumsu* student[5]; 
  for (int i=0;i<5;i++) student[i]=malloc(sizeof(struct st_jumsu));
  
  save_jumsu(student,5);
  
  printf("번호 국어 영어 수학 총점 평균\n");
  for (int i=0;i<5;i++) {
    printf("%-2d %d %d %d %d %.1f\n",i+1,student[i]->kor,student[i]->eng,student[i]->mat,student[i]->sum,student[i]->average);
    fprintf(file1,"%-2d %d %d %d %d %.1f\n",i+1,student[i]->kor,student[i]->eng,student[i]->mat,student[i]->sum,student[i]->average);
  }
  printf("jumsu.txt에 저장함.\n");
  
  return 0;
}

void save_jumsu(struct st_jumsu* list[], int count) {
  for (int i=0;i<count;i++) {
    printf("%d번째 학생의 국어, 영어, 수학점수는? ",i+1);
    scanf("%d %d %d",&list[i]->kor,&list[i]->eng,&list[i]->mat);
    list[i]->sum=list[i]->kor+list[i]->eng+list[i]->mat;
    list[i]->average=list[i]->sum/3.0;
  }
}