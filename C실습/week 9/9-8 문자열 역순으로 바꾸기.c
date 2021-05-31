#include <stdio.h>
#include <string.h>

void reverse_string(char* str); 

int main(void) {
  char str[20];
  
  printf("문자열 입력");
  fgets(str,100,stdin);
  str[strlen(str)-1]='\0';
  reverse_string(str);

  return 0;
}

void reverse_string(char* str){
  int num;
  char mon;
  int i;
  
  num=strlen(str);
  for (i=0;i<num/2;i++) {
    mon=str[i];
    str[i]=str[num-i-1];
    str[num-i-1]=mon;
  }
  printf("역순으로 변환한 문자열은 %s",str);

}