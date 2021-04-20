// 여러 방향 사각형

#include <stdio.h>

int main(void) {
  int len, hei, way;
  scanf("%d %d %d",&len,&hei,&way);
  
  if (way==0) {
    for (int i=0;i<len;i++) printf("#");
    printf("\n");
    for (int i=0;i<hei-2;i++) {
      printf("#");
      for (int j=0;j<len-2;j++) printf(" ");
      printf("#\n");
    }
    for (int i=0;i<len;i++) printf("#");
  }
  else if (way==1) {
    for (int i=0;i<len;i++) printf("#");
    printf("\n");
    for (int i=0;i<hei-2;i++) {
      for (int j=0;j<=i;j++) printf(" ");
      printf("#");
      for (int j=0;j<len-2;j++) printf(" ");
      printf("#\n");
    }
    for (int i=0;i<=hei-2;i++) printf(" ");
    for (int i=0;i<len;i++) printf("#");
  }
  if (way==2) {
    for (int i=0;i<=hei-2;i++) printf(" ");
    for (int i=0;i<len;i++) printf("#");
    printf("\n");
    for (int i=0;i<hei-2;i++) {
      for (int j=hei-2;j>i;j--) printf(" ");
      printf("#");
      for (int j=0;j<len-2;j++) printf(" ");
      printf("#\n");
    }
    for (int i=0;i<len;i++) printf("#");
  }

  return 0;
}