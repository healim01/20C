#include <stdio.h>
#include <string.h>

int main(void) {
  int countUp=0; //대문자 수 
  int countLow=0; //소문자 수
  int countSpace=0; //빈칸 수
  char mon[100][10];
  int i=0, a;
  FILE * file1;
  file1=fopen("data.txt","r");
  
  while (!feof(file1)) {
    fgets(mon[i],100,file1);
    a=strlen(mon[i]);
    for (int j=0;j<a;j++) {
      if (mon[i][j]==' ') countSpace++;
      if (mon[i][j]>='a' && mon[i][j]<='z') countLow++;
      if (mon[i][j]>='A' && mon[i][j]<='Z') countUp++;
    }
    i++;
  }
  printf(">> 대문자 : %d개, 소문자 : %d개, 공백 : %d개\n",countUp,countLow,countSpace);
  return 0;
}