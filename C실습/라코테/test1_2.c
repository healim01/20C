#include <stdio.h>

/*
1. 인원수 입력받기 

2. 입력된 인원수만큼 체온 묻기 

3. 체온 구간 판정 내리기 

4. 체온 구간 중 발열 의심에서만 최고 체온 구하기 

5. 저체온 구간에서만 최저 체온 구하기 

6. 정상체온에서 평균 체온 구하기 

7. 각 구간에 아무도 없을시 0도로 표시 
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
	  if (degree<35.0) {
	    count1++;
	    if (count1==1) min=degree;
	    else if (degree<min) min=degree;
	  }
	  else if (degree<=37.5) {
	    count2++;
	    sum+=degree;
	  }
	  else {
	    count3++;
	    if (count3==1) max=degree;
	    else if (degree>max) max=degree;
	  }
	}
	if (count2!=0) avg=sum/count2;
	else avg=0.0;
	printf("정상체온 : %d명(평균 %.1f도), 발열의심 : %d명(최고 %.1f도), 저체온의심 : %d명(최저 %.1f도)\n",count2,avg,count3,max,count1,min);
	
	
	
  return 0;
}