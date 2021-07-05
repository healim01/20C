#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user_struct{
    char userid[20];
    char userpw[20];
};

int add_user(struct user_struct* userlist[], int size); 
void all_user(struct  user_struct  * userlist[], int size); 

int main(void) {
	struct user_struct* userlist[50]; // 최대 50명의 로그인 데이터 보관용 포인터 배열
	int user_count = 0; // 등록된 사용자 수 
	
	while (1){
		user_count = add_user(userlist, user_count);
		if (user_count==10) break;
	}
	all_user(userlist, user_count);

	return 0;
}

int add_user(struct user_struct* userlist[], int size){
  userlist[size]=malloc(sizeof(struct user_struct));
  int num1, num2, same=0;;
  
  printf("%d번째 사람 ID Password? ",size+1);
  scanf("%s %s",userlist[size]->userid,userlist[size]->userpw);
  num1=strlen(userlist[size]->userid);
  num2=strlen(userlist[size]->userpw);
  if (num1<4) printf("ID는 4글자 이상으로 입력해주세요.\n");
  else if (num2<4) {
    printf("Password는 4글자 이상으로 입력해주세요.\n");
    return size;
  }
  
  for (int i=0;i<size;i++) {
    if (strcmp(userlist[i]->userid,userlist[size]->userid)==0) {
      printf("동일한 ID가 이미 등록되어 있습니다.\n");
      same=1;
      break;
    }
  }
  
  
  if (num1>3 && num2>3 && same==0) size++;
  
  return size;
}

void all_user(struct  user_struct  * userlist[], int size) {
  printf("\n등록된 사용자 목록\n");
  printf("No ID   Password\n");
  for (int i=0;i<size;i++) {
	  printf("%d  %s %s\n",i+1,userlist[i]->userid,userlist[i]->userpw);
	}
}