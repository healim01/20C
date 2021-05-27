#include <stdio.h>
#include <string.h>

int main(void) {
  char firstname[30];         
  char lastname[30]; 
  char age_group[4][30] = {"[Youth]","[Junior]","[Senior]","[Silver]"};
  char total[80];
  int birthyear; 
  int age, group;
  
  printf("Firstname?");
  scanf("%s",firstname);
  printf("Lastname?");
  scanf("%s",lastname);
  printf("Birthyear?");
  scanf("%d",&birthyear);
  
  age=2020-birthyear+1;
  if (age<20) group=0;
  else if (age<40) group=1;
  else if (age<65) group=2;
  else group=3;
  
  strcat(total,age_group[group]);
  strcat(total," ");
  strcat(total,firstname);
  strcat(total," ");
  strcat(total,lastname);
  
  printf("결과: %s\n",total);

    
  return 0;
}
