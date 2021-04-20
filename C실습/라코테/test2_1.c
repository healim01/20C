#include <stdio.h>
/*
1. 인원수 입력받기 

2. 인원수만큼 온도 입력 받기 

3. 온도 구간 측정하여 정상, 발열, 저체온 판정하기 

4. 최고 체온 선정하고 몇번째 사람인지 확인

5. 최저 체온 선정하고 몇번째 사람인지 확인

6. 모든 인원 온도 합하기 

7. 입력된 인원수로 나눠 평균체온 구하기 
*/

int main(void) {
	int persons, count1=0, count2=0, count3=0;
	float degree[20]; // 최대 20명의 체온 
	float min=0, max=0, sum=0, avg;
	int min_i=0, max_i=0;
	int i;
	
	printf("인원수를 입력하시오 >");
	scanf("%d",&persons);
	
	for (i=0;i<persons;i++) {
	  printf("%d번 분의 체온을 입력하시오 >",i+1);
	  scanf("%f",&degree[i]);
	  if (degree[i]<35.0) count1++;
	  else if (degree[i]<=37.5) count2++;
	  else count3++;
	  sum+=degree[i];
	  if (i==0) {
	    max=degree[i];
	    min=degree[i];
	    max_i=i+1;
	    min_i=i+1;
	  }
	  if (degree[i]>max) {
	    max=degree[i];
	    max_i=i+1;
	  }
	  if (degree[i]<min) {
	    min=degree[i];
	    min_i=i+1;
	  }
	}
	if (sum!=0) avg=sum/persons;
	else avg=0;
	printf("정상체온 : %d명, 발열의심: %d명, 저체온의심 : %d명\n",count2,count3,count1);
	printf("최고체온 : %.1f ",max);
	if (max_i!=0) printf("(%d번 분)\n",max_i);
	printf("최저체온 : %.1f ",min);
	if (min_i!=0) printf("(%d번 분)\n",min_i);
	printf("평균체온 : %.1f",avg);
	



  return 0;
}