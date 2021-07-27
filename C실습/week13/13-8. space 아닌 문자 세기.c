#include <stdio.h>
#include <string.h>

int r_strlen(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("length : %d\n", r_strlen(line));
	return 0;
}

int r_strlen(char* str) {
  int count;
  if (strlen(str)>1) count=r_strlen(str+1);
  if (strlen(str)==1) {
    if (str[0] !=' ' && str[0] !='\n' && str[0]!='\t') count=1;
    else count=0;
  }
  else {
    if (str[0] !=' ' && str[0] !='\n' && str[0]!='\t') count++; 
  }
  
  return count;
}