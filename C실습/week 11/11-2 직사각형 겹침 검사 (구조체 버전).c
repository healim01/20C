#include <stdio.h>
struct rectangle{ 
    int x1, y1; // 좌상점 좌표값 (왼쪽 위 모서리) 
    int x2, y2; // 우하점 좌표값 (오른 아래 모서리) 
}; 

int check_overlap(struct rectangle* r1, struct rectangle* r2); // 겹치면 1리턴, 아니면 0리턴

int main(void) {
  int num;
  
  struct rectangle rec1, rec2;
  printf("첫번째 직사각형 좌상점 좌표값(x, y)? ");
  scanf("%d %d",&rec1.x1,&rec1.y1);
  printf("첫번째 직사각형 우하점 좌표값(x, y)? ");
  scanf("%d %d",&rec1.x2,&rec1.y2);
  printf("두번째 직사각형 좌상점 좌표값(x, y)? ");
  scanf("%d %d",&rec2.x1,&rec2.y1);
  printf("두번째 직사각형 우하점 좌표값(x, y)? ");
  scanf("%d %d",&rec2.x2,&rec2.y2);
  
  num=check_overlap(&rec1, &rec2);
  if (num==1) printf("두 직사각형은 겹칩니다.");
  else printf("두 직사각형은 겹치지 않습니다.");
  
  return 0;
}

int check_overlap(struct rectangle* r1, struct rectangle* r2) {
  if (r2->x1 < r1->x2 && r2->x1 > r1->x1 && r2->y1 < r1->y1 && r2->y1 > r1->y2) return 1;
  else if (r2->x2 < r1->x2 && r2->x2 > r1->x1 && r2->y2 < r1->y1 && r2->y2 > r1->y2) return 1;
  else if (r2->x1 < r1->x2 && r2->x1 > r1->x1 && r2->y2 < r1->y1 && r2->y2 > r1->y2) return 1;
  else if (r2->x2 < r1->x2 && r2->x2 > r1->x1 && r2->y1 < r1->y1 && r2->y1 > r1->y2) return 1;
  else if (r1->x1 < r2->x2 && r1->x1 > r2->x1 && r1->y1 < r2->y1 && r1->y1 > r2->y2) return 1;
  else if (r1->x2 < r2->x2 && r1->x2 > r2->x1 && r1->y2 < r2->y1 && r1->y2 > r2->y2) return 1;
  else if (r1->x1 < r2->x2 && r1->x1 > r2->x1 && r1->y2 < r2->y1 && r1->y2 > r2->y2) return 1;
  else if (r1->x2 < r2->x2 && r1->x2 > r2->x1 && r1->y1 < r2->y1 && r1->y1 > r2->y2) return 1;
  return 0;
  
}
