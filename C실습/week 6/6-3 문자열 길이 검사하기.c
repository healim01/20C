#include <stdio.h>
#include <string.h>

int main(void) {
  int i , a;
  int max, min;
  int maxi, mini;
  
  char names[13][100]={
  "Global Leadership School",
  "International Studies, Languages and Literature",
  "Management and Economics",
  "Law",
  "Counseling Psychology and Social Welfare",
  "Communication Arts",
  "Spatial Environment System Engineering",
  "Mechanical and Control Engineering",
  "Contents Convergence Design",
  "Life Science",
  "Computer Science and Electrical Engineering",
  "Global Entrepreneurship and ICT",
  "Creative Convergence Education"};
  
  for (i=0;i<13;i++) {
    a=strlen(names[i]);
    if (i==0) {
      max=a;
      min=a;
      maxi=i;
      mini=i;
    }
    if (max<a) {
      max=a;
      maxi=i;
    }
    if (min>a) {
      min=a;
      mini=i;
    }
  }
  printf("가장 긴 학부 이름은 %s\n",names[maxi]);
  printf("가장 짧은 학부 이름은 %s입니다. ", names[mini]);
  
  return 0;
}