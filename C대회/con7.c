// 비밀번호 강력도

#include <stdio.h>
#include <string.h>

int main(void) {
  char password[80];
  int num;
  int small=0, big=0, number=0, spec=0;
  char spc[20]="!@#$%^&/~()[]{}<>,.?";


  scanf("%s",password);
  num=strlen(password);
  
  for (int i=0;i<num;i++) {
    if (password[i]>='a'&& password[i]<='z') small=1;
    else if (password[i]>='A' && password[i]<='Z') big=1;
    for (int j=1;j<10;j++) {
      if (password[i]-'0'==j) number=1;
    }
    for (int j=0;j<20;j++) {
      if (password[i]==spc[j]) spec=1;
    }
  }


  if (num<8) printf("No Good! (use more than 7 chars)\n");
  else if (small!=1 || big!=1) printf("No Good! (use both upper and lower chars)\n");
  else if (number!=1) printf("No Good! (use a numerical char)\n");
  else if (spec!=1) printf("No Good! (use a special char)\n");
  else printf("Good Password!\n");
  return 0;
}