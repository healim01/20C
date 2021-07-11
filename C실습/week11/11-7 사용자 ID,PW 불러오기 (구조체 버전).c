#include <stdio.h>
struct user_struct{
  char userid[20];
  char userpw[20];
};


int main(void) {
  struct user_struct p[20];
  int i=0;
  FILE * data;
  data=fopen("user.txt","r");
  printf("등록된 사용자 목록\n");
  printf("No ID   Password\n");
  for (int i=0;i<10;i++) {
    if (!fscanf(data,"%s %s",p[i].userid, p[i].userpw)) break;
    printf("%-2d %-4s %-4s\n",i+1,p[i].userid,p[i].userpw);
  }
	fclose(data);
	
	return 0;
}