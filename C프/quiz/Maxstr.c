#include <stdio.h>
#include <string.h>

int main(void) {
  int max, maxi, count=1;
  int num;
  char str[100];

  printf("입력 : ");
  scanf("%s",str);
  num=strlen(str);
  
  for (int i=0;i<num;i++) {
    if (str[i]==str[i-1]) count++;
    else {
      if (count>max){
        max=count;
        maxi=i-1;
      }
      count=1;
    }
  }
  printf("출력 : %c %d",str[maxi],max);
  return 0;
}