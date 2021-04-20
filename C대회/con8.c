// 사전 만들기

#include <stdio.h>
#include <string.h>

int main(void) {
  char word[20][20];
  char str[20];
  int num;
  int len[20];
  int gil;
  int same=0;

  scanf("%d",&num);
  for (int i=0;i<num;i++) {
    scanf("%s",word[i]);
    len[i]=strlen(word[i]);
  }

  for (int i=0;i<num;i++) {
    same=0;
    for (int j=0;j<(num-i);j++) {
      if (len[j]>=len[j+1]) {
        if (len[j]==len[j+1] && strcmp(word[j], word[j+1])>0) same=1;
        else {
          strcpy(str,word[j]);
          strcpy(word[j],word[j+1]);
          strcpy(word[j+1],str);
          gil=len[j];
          len[j]=len[j+1];
          len[j+1]=gil;
        }
      }
    }
  }
  printf("Sorted.\n");
  for (int i=0;i<num;i++) printf("%s\n",word[i]);
  
  return 0;
}