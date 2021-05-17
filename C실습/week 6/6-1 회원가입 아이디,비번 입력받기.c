#include <stdio.h>
#include <string.h>

int main() {
  char userid[30];         
  char password[30]; 
  char name[30]; 
  int i,a;
  
  printf("User Id?");
  scanf("%s",userid);
  while (1) {
    printf("Password?");
    scanf("%s",password); 
    a=strlen(password);
    if (password[2]!=0) break; 
    printf("--> 3글자 이상 입력할 것\n");
  }
  printf("User Name?");
  scanf("%s",name);
  
  printf("\nUser Id: %s\n",userid);
  printf("Password: ");
  for (i=0;i<a;i++) {
    if (i<2) printf("%c",password[i]);
    else printf("*");
  }
  printf("\nUser Name: %s",name);

  
	return 0;
} 