#include <stdio.h>
#include <string.h>

void r_print(char* pch);
// pch : 문자열의 시작문자를 가리키는 포인터

int main(void) {
	char str[80];
	printf("Enter a string >>");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
	r_print(str);
	printf("\n");
	return 0;
}
void r_print(char* pch){
  printf("%s\n",pch);
  if (strlen(pch)>1) r_print(pch+2);
  if (strlen(pch)==1) {
    if (pch[0]>='a' && pch[0]<='z') printf("%c",pch[0]+('A'-'a'));
    else printf("%c",pch[0]);
  }
  if (pch[0]>='a' && pch[0]<='z') printf("%c",pch[0]+('A'-'a'));
  else printf("%c",pch[0]);
  else {
    if (pch[0]>='a' && pch[0]<='z') printf("%c",pch[0]+('A'-'a'));
    else printf("%c",pch[0]);
    if (pch[1]>='a' && pch[1]<='z') printf("%c",pch[1]+('A'-'a'));
    else printf("%c",pch[1]);
  }
  
}
