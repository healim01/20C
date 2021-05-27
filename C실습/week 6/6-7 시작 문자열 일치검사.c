#include <stdio.h>
#include <string.h>

int main(void) {
  int i, count=0;
  char word[80];
  int a;
  char names[13][100]={"Global Leadership School",
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
    "Creative Convergence Education"
  };
  
  printf("Input >>");
  scanf("%s",word);
  a=strlen(word);
  printf("Matching : ");
  for (i=0;i<13;i++) {
    if (strncmp(names[i],word,a)==0) {
      printf("[%s] ",names[i]);
      count++;
    }
  }
  printf("\n%d major found",count);
  return 0;
}