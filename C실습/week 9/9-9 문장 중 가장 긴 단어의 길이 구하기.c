#include <stdio.h>
#include <string.h>

char* findLongestWord(char* str);
int max;

int main(void) {
  int i;
  char word[100];
	char line[100]; // 입력받을 문장
	printf("문장 입력 >");

	fgets(line, 100, stdin);
	line[strlen(line)-1]='\0';
	strcpy(word,findLongestWord(line));

	printf("결과 > %s 중에 가장 긴 단어는 ",line);
	for (i=0;i<max;i++) printf("%c",word[i]);
	printf(", 길이 %d입니다.",max);
	return 0;
}

char* findLongestWord(char* str) {
  int maxi;
  int num, i=0;
  
  while (1) {
    num=0;
    while (str[i]!=' ') {
      i++;
      num++;
      if (str[i]=='\0') break;
    }
    i++;
    if (num>max) {
      max=num;
      maxi=i-num-1;
    }
    if (str[i]=='\0') break;
  }

  return &str[maxi];
}