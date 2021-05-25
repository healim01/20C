#include <stdio.h>

int main(void) {
  int number[5][3]; // 각 집의 거주자 수
  int floor_total[5]; // 층별 거주자 합계 (1층, 2층, 3층, 4층, 5층)
  int line_total[3];  // 호수별 거주자 합계 (1호라인, 2호라인, 3호라인)
  int total;  // 아파트의 총 거주자 수
  int i, j; // 반복문 사용을 위한 변수 
  
  for (i=0;i<5;i++) {
    for (j=0;j<3;j++) {
      printf("%d0%d호에 살고 있는 사람의 수?",i+1,j+1);
      scanf("%d",&number[i][j]);
      floor_total[i]+=number[i][j];
      line_total[j]+=number[i][j];
      total+=number[i][j];
    }
  }
  for (i=0;i<5;i++) printf("%d층에 살고 있는 사람의 수 %d명\n",i+1,floor_total[i]);
  printf("\n");
  for (i=0;i<3;i++) printf("%d호라인에 살고 있는 사람의 수 %d명\n",i+1,line_total[i]);
  printf("\n");
  printf("이 아파트에 사는 사람 모두 %d명",total);
  return 0;
}