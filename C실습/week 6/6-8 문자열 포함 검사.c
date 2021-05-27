#include <stdio.h>
#include <string.h>

int main(void) {
  char word[80];
  int i, count=0;
  char names[13][100]={ "Global Leadership School",  
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
  printf("Matching : ");
  for (i=0;i<13;i++) {
    if (strstr(names[i],word)!=0) {
      printf("[%s] ",names[i]);
      count++;
    }
  }
  printf("\n\n%d major found",count);
  return 0;
}