#include <stdio.h>
#include <stdlib.h>
struct user_struct{
    char userid[20];
    char userpw[20];
};

int add_user(struct user_struct* userlist[], int size); 

int main(void) {
	struct user_struct* userlist[50]; // 최대 50명의 로그인 데이터 보관용 포인터 배열
	int user_count = 0; // 등록된 사용자 수 
	
	for(int i=0; i<10; i++){
		user_count = add_user(userlist, user_count);
	}
	for (int i=0;i<user_count;i++) {
	  printf("%d번째 사람 ID(%s) Password(%s)\n",i+1,userlist[i]->userid,userlist[i]->userpw);
	}// 여기부터 코드 작성.
	
	return 0;
}

int add_user(struct user_struct* userlist[], int size){
  userlist[size]=malloc(sizeof(struct user_struct));
  
  printf("%d번째 사람 ID Password? ",size+1);
  scanf("%s %s",userlist[size]->userid,userlist[size]->userpw);
  size++;
  
  return size;
}
