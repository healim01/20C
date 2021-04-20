#include <stdio.h>
int month_start(int year, int month);
int days_count(int year,int num);
int print_calendar (int num,int day);

int main(void) {
  int year, month;
  int first, days;
  printf("출력 원하는 년, 월 입력 :");
  scanf("%d %d",&year,&month);

  first=month_start(year, month);
  days=days_count(year,month);
  print_calendar(first,days);

  
  return 0;
}

int month_start(int years, int month) {
  int year;
  int ly, ls;
  int a, i;
  int total=0;
  int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};

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
  a=total%7+1;

  return a;
}

int days_count (int year, int num) {
  int ly;
  int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};

  if (year%4==0) {
    if (year%100==0) {
      if (year%400==0) ly=1;
      else ly=0;
    }
    else ly=1;
  }
  else ly=0;

  if (ly==1 && num==2) return 29; 
  else return months[num-1];
}

int print_calendar (int day,int num) {
  int i;
  int count=1;

  day=day%7;

  printf("Sun    Mon    Tue    Wed    Thu   Fri    Sat\n");
  for (i=0;i<day;i++) {
    printf("       ");
    count++;
  }

  for (i=1;i<=num;i++) {
    if (i<10) printf("%d      ",i);
    else printf("%d     ",i);

    if (count%7==0) printf("\n");
    count++;
  }

  return 0;
} 