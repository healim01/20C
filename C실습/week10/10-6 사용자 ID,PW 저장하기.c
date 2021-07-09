#include <stdio.h>

int main(void) {
  FILE * file1;
  file1=fopen("user.txt","w");
	char userid[10][20];
	char userpw[10][20];
	int i;
	
	for (i=0;i<10;i++) {
	  printf("%d번째 사람 ID Password? ",i+1);
	  scanf("%s %s",userid[i],userpw[i]);
	}
	
	printf("\n등록된 사용자 목룍\n");
	printf("No  ID   Password\n");
	for (i=0;i<10;i++) {
	  printf("%d %-2s %s\n",i+1,userid[i],userpw[i]);
	  fprintf(file1,"%-2s %-2s\n",userid[i],userpw[i]);
	}
	printf("\nuser.text에 저장함");
	fclose(file1);

	return 0;
}