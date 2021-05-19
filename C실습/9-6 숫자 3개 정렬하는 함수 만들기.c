#include <stdio.h>
void sort3num(int* n1, int* n2, int* n3); 

int main(void) {
	int num1, num2, num3;
	printf("숫자 3개 입력 ");
	scanf("%d %d %d", &num1, &num2, &num3);
	sort3num(&num1, &num2, &num3);
	printf("정렬 결과 %d %d %d\n", num1, num2, num3);
	return 0;
}

void sort3num(int* n1, int* n2, int* n3){
  int num;
  if (*n1<*n2) {
    num=*n1;
    *n1=*n2;
    *n2=num;
  }
  if (*n2<*n3) {
    num=*n2;
    *n2=*n3;
    *n3=num;
  }
  if (*n1<*n2) {
    num=*n1;
    *n1=*n2;
    *n2=num;
  }
}