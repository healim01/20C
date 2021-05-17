#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int lotto[6]; 
  int count; 
  int onemore; 
  int i; 
  
  srand(time(0));
  while (1) {
    while (1) {
      lotto[count]=rand()%45+1;
      for (i=0;i<count;i++) {
        if(lotto[i]==lotto[count]) count--;
      }
      count++;
      if (count==6) break;
    }
    count=0;
    
    printf("생성된 로또 번호는 ");
    for (i=0;i<6;i++) printf(" %d ",lotto[i]);
    printf("입니다.\n더 만드시겠습니까? (1:Yes, 2:No) >> ");
    scanf("%d",&onemore);
    if (onemore==2) break;
  }

  return 0;
}