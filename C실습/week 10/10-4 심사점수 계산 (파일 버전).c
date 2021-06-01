#include <stdio.h>

float Max(float num[], int size);
float Min(float num[], int size);

int main(void) {
  FILE * file1;
  float max, min;
  float num[10];
  float sum=0, avg;
  file1=fopen("data.txt","r");
  for (int i=0;i<10;i++) {
    fscanf(file1,"%f",&num[i]);
    printf("%d번 심사점수 : %.1f\n",i+1, num[i]);
    sum+=num[i];
  }
  max=Max(num,10);
  min=Min(num,10);
  sum=sum-max-min;
  avg=sum/8.0;
  printf("가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균은 %.1f 입니다.",avg);
  fclose(file1);
  return 0;
}

float Max(float num[], int size){
  float max;
  for (int i=0;i<size;i++) {
    if (num[i]>max || i==0) max=num[i];
  }
  return max;
}

float Min(float num[], int size){
  float min;
  for (int i=0;i<size;i++) {
    if (num[i]<min || i==0) min=num[i];
  }
  return min;
}