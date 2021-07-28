#include <stdio.h>
#include <math.h>
// pow() 함수 활용

int main(void) {
  int number[5]; // 입력받은 5개의 숫자
  int pow_value[5][5]; // 임의의 두 수 a, b로 만들 수 있는 a^b의 값 들
  int max=1, min=100;  // 최댓값과 최솟값
  int num;
  int max_a=2, max_b=2; // 최댓값을 만들어 내는 경우의 a와 b의 값
  int min_a=9, min_b=9;  // 최솟값을 만들어 내는 경우의 a와 b의 값
  int i, j;  // 반복문을 위한 변수 

  printf("2에서 9사이의 숫자 5개를 입력하세요. ");
  scanf("%d %d %d %d %d",&number[0],&number[1],&number[2],&number[3],&number[4]);
  
  for (i=0;i<5;i++) {
    for (j=0;j<5;j++) {
      num=pow(number[i],number[j]);
    
      if (i!=j && num>max) {
        max_a=number[i];
        max_b=number[j];
        max=num;
      }
      if (i!=j && num<min) {
        min_a=number[i];
        min_b=number[j];
        min=num;
      }
    }
  }
  
  printf("\n입력하신 5개의 수로 제곱수를 만들면...\n");
  printf("가장 큰수는 %d의 %d승인 %d입니다.\n",max_a,max_b,max);
  printf("가장 작은 수는 %d의 %d승인 %d입니다.",min_a,min_b,min);

  return 0;
}