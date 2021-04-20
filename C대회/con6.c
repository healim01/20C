// 문자열 거꾸로 출력

#include <stdio.h>
#include <string.h>

int main(void) {
  char word[100];
  char reword[100];
  int num;

  fgets(word,100,stdin);
  word[strlen(word)-1]='\0';
  num=strlen(word);

  for (int i=0;i<num;i++) {
    if (word[i]==' ') word[i]='_';
  }
  for (int i=0;i<num;i++) {
    reword[num-i-1]=word[i];
  }
  printf("Converted : %s\n",word);
  printf("Reversed : %s\n",reword);
  return 0;
}