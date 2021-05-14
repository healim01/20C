#include <stdio.h>
#include <string.h>

int main(void) {
  char str[100];
  int num, yn;

  printf("입력 : ");
  scanf("%s",str);
  num=strlen(str);

  for (int i=0;i<num/2;i++) {
    if (str[i]!=str[num-i-1]) {
      printf("출력 : NO");
      yn=1;
      break;
    }
  }
  if (yn==0) printf("출력 : YES");
  return 0;
}