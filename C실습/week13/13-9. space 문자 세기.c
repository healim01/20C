#include <stdio.h>
#include <string.h>

int r_spaces(char* str);

int main(void) {
	char line[100];
	printf("Enter a string > ");
	fgets(line, 100, stdin);
	printf("spaces : %d\n", r_spaces(line));
	return 0;
}

int r_spaces(char* str) {
  int count;
  if (strlen(str)>1) count=r_spaces(str+1);
  if (strlen(str)==1) {
    if (str[0]==' ' || str[0] =='\t') count=1;
    else count=0;
  }
  else {
    if (str[0]==' ' || str[0] =='\t') count++; 
  }
  
  return count;
}
