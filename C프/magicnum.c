#include <stdio.h>

int main(void) {
  int ms[50][50];
  int size;
  int i, j;
  int h, y;

  printf("Magic square size : ");
  scanf("%d",&size);

  for (i=1;i<=(size*size);i++) {
    if (i==1) {
      h=0;
      y=size/2;
      ms[h][y]=i;
    }
    else if ((i-1)%size==0) h++;

    else {
      if (h>0) h--;
      else h=size-1;
      if (y>0) y--;
      else y=size-1;
    }
    ms[h][y]=i;
  }

  for (i=0;i<size;i++) {
    for (j=0;j<size*6;j++) printf("-");
    printf("\n");
    for (j=0;j<size;j++) printf("| %d  ",ms[i][j]);
    printf("|");
    printf("\n");
  }
  for (j=0;j<size*6;j++) printf("-");
 
  return 0;
}