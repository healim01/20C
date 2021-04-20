#include <stdio.h>

int main(void) {
  int year, month, day ;
  int years;
  int ly, ls;
  int a, i;
  int total;
  int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};

  printf("입력 : ");
  scanf("%d %d %d",&years,&month,&day);
  year=years-1;

  for (i=1900;i<=year;i++) {
    if (i%4==0) {
      if (i%100==0) {
        if (i%400==0) ly=1;
        else ly=0;
      }
      else ly=1;
    }
    else ly=0;

    if (ly==1) total+=2;
    else total+=1;
  }

  if (years%4==0) {
    if (years%100==0) {
      if (years%400==0) ls=1;
      else ls=0;
    }
    else ls=1;
  }
  else ls=0;

  if (ls==1 && month>2) total+=1;

  for (i=0;i<month-1;i++) total+=months[i];
  total+=day-1;

  a=total%7;

  if (a==0) printf("Monday");
  else if (a==1) printf("Tuesday");
  else if (a==2) printf("Wednesday");
  else if (a==3) printf("Thursday");
  else if (a==4) printf("Friday");
  else if (a==5) printf("Saturday");
  else printf("Sunday");



  return 0;
}