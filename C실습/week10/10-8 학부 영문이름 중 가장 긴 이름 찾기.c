#include <stdio.h>
#include <string.h>

int main(void) {
  char name[20][80];
  int i=0, num;
  int max, min;
  int maxi, mini;
  FILE * file1;
  file1=fopen("name.txt","r");
  
  while (!feof(file1)) {
    fgets(name[i],100,file1);
    num=strlen(name[i]);
    if (num>max || i==0) {
      max=num;
      maxi=i;
    }
    if (num<min || i==0) {
      min=num;
      mini=i;
    }
    i++;
  }
  printf("Count : %d\n",i);
  printf("Longest name : %s",name[maxi]);
  printf("Shortest name : %s",name[mini]);


  return 0;
}