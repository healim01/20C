#include <stdio.h>
#include <string.h>

int main(void) {
  int i, num, a, b;
  int anag=0;
  char str1[80];
  char str2[80];
  int alphacount1[26]={0}, alphacount2[26]={0};

  printf("String 1 >");
  fgets(str1,80,stdin);
  a=strlen(str1);
  printf("String 2 >");
  fgets(str2,80,stdin);
  b=strlen(str2);
  
  for (i=0;i<a;i++) {
    num=str1[i]-'a';
    alphacount1[num]++;
  }
  
  for (i=0;i<b;i++) {
    num=str2[i]-'a';
    alphacount2[num]++;
  }
  
  for (i=0;i<26;i++) {
    if (alphacount1[i]!=alphacount2[i]) {
      anag=1;
      break;
    }
  }
  
  if (anag==0) printf("Anagram!");
  else printf("Not anagram!");
  
  return 0;
}