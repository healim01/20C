#include <stdio.h>
#include <string.h>

int main(void) {
  int i, a;
  char str[100]; // 입력받은 문자열 
  char reverse[100]; // 문자열의 역순 문자열

  printf("문자열 입력");
  fgets(str,100,stdin);
  str[strlen(str)-1]='\0';
  a=strlen(str);
  
  // hello\0
  for (i=a;i>=0;i--) {
    reverse[a-i-1]=str[i];
  }

  printf("역순으로 변환된 문자열은 %s",reverse);
  return 0;
}