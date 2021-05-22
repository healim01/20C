#include <stdio.h>

int main() {
	int size;
	int stars=1, blanks;
	int i,j;
	printf("size? >> ");
	scanf("%d",&size);
	blanks=2*size-2;
	
	for (i=0;i<size;i++) {
	  for (j=0;j<stars;j++) printf("*");
	  for (j=0;j<blanks;j++) printf(" ");
	  for (j=0;j<stars;j++) printf("*");
	  blanks=blanks-2;
	  stars++;
	  printf("\n");
	}
	stars--;
	blanks=blanks+2;
	for (i=0;i<size-1;i++) {
	  blanks=blanks+2;
	  stars--;
	  for (j=0;j<stars;j++) printf("*");
	  for (j=0;j<blanks;j++) printf(" ");
	  for (j=0;j<stars;j++) printf("*");
	  printf("\n");
	}

	return 0;
}