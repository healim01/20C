#include <stdio.h>
#include <string.h>

int main(void) {
  int i, num;
  char name[20];
  char pass[20];
  char username[5][20]={"kim", "lee", "park", "hong", "choi"};
  char password[5][20]={"1111", "1234", "3456", "3535", "7777"};
  
  printf("아이디를 입력하시오.");
  scanf("%s",name);
  printf("비밀번호를 입력하시오.");
  scanf("%s",pass);
  num=5;
  for (i=0;i<5;i++) {
    if (strcmp(username[i],name)==0) num=i;
  }
  if (num!=5) {
    if (strcmp(password[num],pass)!=0) num=6;
  }
  
  if (num<5) printf("로그인 성공");
  else if (num==5) printf("그런 아이디 없음");
  else if (num==6) printf("아이디는 맞는데 비번이 틀림");
  
  return 0;
}