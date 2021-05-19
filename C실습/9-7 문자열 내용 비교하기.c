#include <stdio.h>
#include <string.h>

int which_first(char * str1, char * str2);

int main(void) {
  int num;
  char str1[20], str2[20];
  
  printf("첫번째 문자열을 입력하시오. -->");
  scanf("%s",str1);
  printf("두번째 문자열을 입력하시오. -->");
  scanf("%s",str2);
  num=which_first(str1,str2);
  if (num==1) printf("두번째 문자열이 사전에 먼저 나옵니다.");
  else printf("첫번째 문자열이 사전에 먼저 나옵니다.");
  return 0;
}

int which_first(char * str1, char * str2) {
  if (strcmp(str1, str2)>0) return 1;
  else if (strcmp(str1, str2)<0) return 2;
  return 0;
}