#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int lotto_com[6]; // 컴퓨터가 만들어 낸 로또 번호
  int lotto_user[6];  // 사용자가 입력한 로또 번호
  int i;  // 반복문을 위한 변수
  int count=0;  // 현재 만들어지고 있는 로또 번호의 순서(0, 1, 2, 3, 4, 5)
  int match_count;  // 일치하는 로또 번호의 갯수 (0~6) 
  int same;
  srand(time(0));
  
  while (1) {
    lotto_com[count]=rand()%45+1;
    for (i=0;i<count;i++) {
      if(lotto_com[i]==lotto_com[count]) count--;
    }
    count++;
    if (count==6) break;
  }

  count=0;
  while (1) {
    printf("원하는 %d번째 로또 숫자를 입력",count+1);
    scanf("%d",&lotto_user[count]);
    if (lotto_user[count]>45 || lotto_user[count]<1) {
      printf("--> 잘못 입력\n");
      continue;
    }
    for (i=0;i<count;i++) {
      same=0;
      if (lotto_user[count]==lotto_user[i]) {
        printf("--> 잘못 입력\n");
        same=1;
        count--;
      }
    }
    for (i=0;i<6;i++) {
      if (lotto_user[count]==lotto_com[i]) {
        match_count++;
        if (same==1) match_count--;
      }
    }
    count++;
    if (count==6) break;
  }
  printf("\n이번 주의 로또 당첨 번호는 ");
  for (i=0;i<6;i++) printf("%d ",lotto_com[i]);
  printf("\n일치하는 로또 번호는 %d",match_count);
  
  
  
  return 0;
}