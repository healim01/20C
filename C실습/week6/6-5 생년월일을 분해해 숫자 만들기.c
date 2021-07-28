#include <stdio.h>

int main(void) {
  int i,sum=0;
  char birthdate[8];
  
  printf("Enter your birthdate >> ");
  scanf("%s",birthdate);
  
  for (i=0;i<8;i++) {
    if (i<4) sum+=(birthdate[i]-'0');
    else if (i==4) sum+=(birthdate[i]-'0')*10;
    else if (i==5) sum+=(birthdate[i]-'0');
    else if (i==6) sum+=(birthdate[i]-'0')*10;
    else if (i==7) sum+=(birthdate[i]-'0');
  } 
  printf("Your birthdate number is %d",sum);
  
  return 0;
}