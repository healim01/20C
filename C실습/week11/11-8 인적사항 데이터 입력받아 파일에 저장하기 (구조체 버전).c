#include <stdio.h>
#include <string.h>
struct person_struct{
    char name[20];
    char address[80];
    int age;
}; 

int main(void) {
  struct person_struct p[3];
  for (int i=0;i<3;i++) {
    if (i==0) printf("첫번째 사람 인적사항을 입력하시오.\n");
    else if (i==1) printf("두번째 사람 인적사항을 입력하시오.\n");
    else if (i==2) printf("세번째 사람 인적사항을 입력하시오.\n");
    
    printf("이름은? ");
    scanf("%s",p[i].name);
    getchar();
    printf("주소는? ");
    fgets(p[i].address,80,stdin);
    p[i].address[strlen(p[i].address)-1]='\0';
    printf("나이는? ");
    scanf("%d",&p[i].age);
    getchar();
  }
  
  printf("첫번째 사람 : %s/ %s/ %d\n",p[0].name,p[0].address,p[0].age);
  printf("두번째 사람 : %s/ %s/ %d\n",p[1].name,p[1].address,p[1].age);
  printf("세번째 사람 : %s/ %s/ %d\n",p[2].name,p[2].address,p[2].age);

  
  return 0;
}