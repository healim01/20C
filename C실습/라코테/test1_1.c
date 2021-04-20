#include <stdio.h>
/*
1. 인원수를 입력받기 

2. 인원수대로 체온을 입력 받기 

3. 입력받은 온도의 체온판정하기 
  3-1) 저체온/ 정상/ 발열의심

4. 입력받은 온도가 최고, 최저 체온인지 확인하기

5. 체온을 더하여 총 합구하기 

6. 이후 인원수 만큼 나눠 평균체온 구하기 

7. 체온 판정 인원수 출력, 최고,최소,평균 체온 출력 

*/

int main(void) {
	int persons, count1=0, count2=0, count3=0;
	float min, max, degree, sum=0, avg;
	int i;
	
	printf("인원수를 입력하시오 > ");
	scanf("%d",&persons);
	
	for (i=0;i<persons;i++) {
	  printf("%d번 분의 체온을 입력하시오 > ",i+1);
	  scanf("%f",&degree);
	  if (degree<35.0) count1++;
	  else if (degree<=37.5) count2++;
	  else count3++;
	  if (i==0) max=degree;
	  else if (degree>max) max=degree;
	  
	  if (i==0) min=degree;
	  else if (degree<min) min=degree;
	  sum+=degree;
	}
	if (persons!=0) avg=sum/persons;
	else avg=0;
	printf("정상체온 : %d명, 발열의심 : %d명, 저체온의심 : %d명\n",count2, count3, count1);
	printf("최고체온 : %.1f, 최저체온 : %.1f, 평균체온 : %.1f\n",max,min,avg);



  return 0;
}