#include <stdio.h>

int main(void) {
  FILE * file1;
	char userid[10][20];
	char userpw[10][20];  
	int i;
	
	file1 = fopen("user.txt","r");
	for (i=0;i<10;i++) fscanf(file1,"%s %s",userid[i],userpw[i]);
	printf("등록된사용자 목록\n");
	printf("No ID    Password\n");
	for (i=0;i<10;i++) {
	  printf("%-2d %-5s %-2s\n",i+1,userid[i],userpw[i]);
	}
	
	return 0;
}