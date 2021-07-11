#include <stdio.h>
struct user_struct{
       char userid[20];
       char userpw[20];
};

int main(void) {
  struct user_struct p[10];
  FILE * data;
  data=fopen("user.txt","w");
  
  for (int i=0;i<10;i++) {
    printf("%d번째 사람 ID Password? ",i+1);
    scanf("%s %s",p[i].userid,p[i].userpw);
    fprintf(data,"%s %s\n",p[i].userid,p[i].userpw);
  }
  printf("\n등록된 사용자 목록\n");
  printf("No ID   Password\n");
  for (int i=0;i<10;i++) printf("%d %s %s\n",i+1,p[i].userid,p[i].userpw);
  printf("\nuser.txt에 저장함");
  
  fclose(data);

	return 0;
}