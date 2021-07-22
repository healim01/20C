#include <stdio.h>

int main(void) {
	int i,j;	// 반복문을 위한 변수
	int jumsu;  // 점수 계산용 변수
	int count;  // 인원수 계산용 변수
	char names[5][20]={"James", "David", "Simon", "Peter", "Jason"}; // 학생 이름
	int sheet[5][10];  // 학생별 답안내용
	int answer[10]={1,2,3,4,1,2,3,4,3,2}; // 정답순서
	int grade[5];  // 학생별 등급

	for(i=0;i<5;i++){
		printf("Enter %s's sheet >> ", names[i]);
		for(j=0;j<10;j++) {
			scanf("%d",&sheet[i][j]); // i번째 학생의 점수 10개 입력 
			if (sheet[i][j]==answer[j]) jumsu++;
		}
		if (jumsu>=9) grade[i]=1;
		else if (jumsu>=7) grade[i]=2;
		else grade[i]=3;
		jumsu=0;
	}
	
	printf("\nGrade result\n");
	printf("1st :");
	for (i=0;i<5;i++) if (grade[i]==1) {
	  printf(" %s ",names[i]);
	  count++;
	}
	printf("(%d)\n2nd :",count);
	count=0;
	for (i=0;i<5;i++) if (grade[i]==2) {
	  printf(" %s ",names[i]);
	  count++;
	}
	printf("(%d)\nFail :",count);
	count=0;
	for (i=0;i<5;i++) if (grade[i]==3) {
	  printf(" %s ",names[i]);
	  count++;
	}
	printf("(%d)\n",count);
	

	return 0;
}