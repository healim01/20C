#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int match_lotto(int lotto1[6], int lotto2[6]);

int main(void) {
  srand(time(0));
  int lotto1[6]; // 컴퓨터가 만들어 낸 로또 번호
  int lotto2[6];  // 사용자가 입력한 로또 번호
  int i;  // 반복문을 위한 변수
  int count=0;  // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
  int match_count=0;  // 일치하는 로또 번호의 갯수 (0~6) 
  
  while (1) {
    lotto1[count]=rand()%45+1;
    for (i=0;i<count;i++) {
      if(lotto1[i]==lotto1[count]) count--;
    }
    count++;
    if (count==6) break;
  }

  count=0;
  while (1) {
    printf("원하는 %d번째 로또 숫자를 입력",count+1);
    scanf("%d",&lotto2[count]);
    if (lotto2[count]>45 || lotto2[count]<1) {
      printf("--> 잘못 입력\n");
      continue;
    }
    for (i=0;i<count;i++) {
      if (lotto2[count]==lotto2[i]) {
        printf("--> 잘못 입력\n");
        count--;
      }
    }
    count++;
    if (count==6) break;
  }
  printf("이번 주의 로또 당첨 번호는 ");
  for (i=0;i<6;i++) {
    printf("%d ",lotto1[i]);
  }
  match_count=match_lotto(lotto1, lotto2);
  printf("\n일치하는 로또 번호는 %d",match_count);
  

  return 0;
}


int match_lotto(int lotto1[6], int lotto2[6]) {
  int count=0;
  int i,j;
  
  for (i=0;i<6;i++) {
    for (j=0;j<6;j++) {
      if (lotto1[i]==lotto2[j]) count++;
    }
  }
  
  return count;
}