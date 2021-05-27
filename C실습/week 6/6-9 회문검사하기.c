#include <stdio.h>
#include <string.h>

int main(void) {
  char word[100];
  char newword[100];
  int a,i,j;
  int pali=0;
  int count=0;
  
  printf("Sentence > ");
  fgets(word,100,stdin);
  word[strlen(word)-1]='\0';
  a=strlen(word);
  for (i=0;i<a;i++) {
    if (word[i]>='a' && word[i]<='z') {
      newword[count]=word[i];
      count++;
    }
  }

  for (i=0;i<count/2;i++) {
  	if( newword[i] != newword[count-i-1] ) {
  	  pali=1;
  	  break;
  	}
	}
	if (pali==0) printf("Palindrome!");
	else printf("Not Palindrome!");
 
  return 0;
}