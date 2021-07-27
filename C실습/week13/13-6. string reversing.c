#include <stdio.h>
#include <string.h>

void r_print(char* pch, int position);
// pch : 문자열의 시작문자를 가리키는 포인터
// position : 해당문자의 순서값(1~)

int main(void) {
	char str[80];
	printf("Enter a string >>");
	fgets(str, 80, stdin);
	str[strlen(str)-1]='\0';
	r_print(str, strlen(str));
	return 0;
}
void r_print(char* pch, int position){
  if (strlen(pch)>1) {
    r_print(pch+1,strlen(pch+1));
  }
  printf("%d. %c\n",position,pch[0]);

}
