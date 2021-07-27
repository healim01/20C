///////////////////////////////////////////
// 1~80 라인까지는 수정할 필요 없음!! (단, 새로운 함수가 꼭 필요하면 추가 가능함))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record{		// 생활관생 관리 레코드
	char name[20];	// 성명				
	char fm;		// 성별 ('F' 여성, 'M' 남성)				
	int entry;		// 입학년도 (4자리 숫자)
	int room;		// 방 호실
	int point;		// 벌점
};

int load_members(struct Record* p[]);		// 목록파일 읽기
void list_members(struct Record* p[], int n);	// 목록 출력(리스트)
void edit_room(struct Record* p[], int n);		// 호실 수정
void make_penalty(struct Record* p[], int n);	// 벌점 부여
void find_members(struct Record* p[], int n);	// 검색 (이름)
void save_report(struct Record* p[], int n);	// 보고서 저장

int main(){
	struct Record* members[100]; 	// 최대 100명까지 관리할 수 있는 포인터 배열
	int count;	// 현재등록된 관생 수
	int menu;	// 메뉴번호

	count = load_members(members);	// 시작 전에 파일로부터 관생 리스트를 모두 읽어온다.
	while(1)
	{
		// 메뉴 출력
		printf("\n[1]목록 [2]호실변경 [3]벌점부여 [4]검색 [5]보고서 저장 [0]종료 >> ");
		scanf("%d",&menu);	// 메뉴를 읽음

		if(menu==1){
			list_members(members, count);	// 목록 출력
		}
		else if(menu==2){
			edit_room(members, count);	// 호실 변경
		}
		else if(menu==3){
			make_penalty(members, count); // 벌점 부여
		}
		else if(menu==4){
			find_members(members, count);	// 검색
		}
		else if(menu==5){
			save_report(members, count);	// 보고서 저장
		}
		else {
			break;
		}
	}
}

int load_members(struct Record* p[]){
	FILE *file;
	int n=0;
	file = fopen("members.txt","rt");
	while(!feof(file)){
		p[n]=(struct Record*)malloc(sizeof(struct Record));
		fscanf(file,"%s %c %d %d %d",p[n]->name,&(p[n]->fm),&(p[n]->entry),&(p[n]->room),&(p[n]->point));
		n++;
	}
	fclose(file);
	printf("%d명이 저장된 파일을 읽었습니다.\n",n);
	return n;
}

void list_members(struct Record * p[], int n){
	int i;
	printf("\n전체목록입니다.\n");
	printf("NO 이름 성별 학번 호실 벌점\n");
	
	for(i=0; i<n; i++){
		printf("%d %s [%c] %d %d %d\n", (i+1), p[i]->name, p[i]->fm, p[i]->entry, p[i]->room, p[i]->point);
	}
}

// 여기까지는 수정할 필요 없음
//////////////////////////////////////////

void edit_room(struct Record* p[], int n){
// 호실변경 함수 --> 14-1 문제

	char name[20];
	struct Record* rp; // 수정할 레코드 구조체의 포인터값
	int i, found=0, newroom;
	int ok=0, count;

	printf("호실 변경하려는 학생 이름은? >> ");
	scanf("%s", name);
	for(i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i];
			break;
		}
	}
	if(found==1){
		printf("이름 성별 학번 호실 벌점\n");
		printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);

		while (1) {
		  count=0;
		  printf("새로운 호실을 입력하시오. >> ");
		  scanf("%d", &newroom); 
		  
		  for (i=0;i<n;i++) {
		      if (newroom==p[i]->room) count++;
		    }
		  
		  if (rp->fm=='F') {
		    if ((newroom<200) && (newroom<101 || newroom>115 )) printf("배정불가(호실 오류)\n");
		    else if (newroom>200) printf("배정불가(층 오류)\n");
		    else if (count>=2) printf("배정불가(인원초과)\n");
		    else ok=1;
		  }
		  else {
		    if ((newroom>200) && (newroom<201 || newroom>215 )) printf("배정불가(호실 오류)\n");
		    else if (newroom<200) printf("배정불가(층 오류)\n");
		    else if (count>=2) printf("배정불가(인원초과)\n");
		    else ok=1;
		  }
		  if (ok==1) {
  		  rp->room = newroom;
  		  printf("수정완료!\n");
  		  break;
  		}
		}
		

	}
	else{
		printf("없는 학생입니다.\n");
	}
}
///////////////////////////////////////////////////
void make_penalty(struct Record* p[], int n){
  int YN, found=0;
  char name[20];
	struct Record* rp; // 수정할 레코드 구조체의 포인터값
// 벌점부과 함수 --> 14-2 문제
  printf("벌점 부여할 학생 이름은? >> ");
  scanf("%s",name);
  for(int i=0;i<n;i++){
		if(strcmp(p[i]->name,name)==0){
			found=1;
			rp=p[i];
			break;
		}
  }
  if(found==1){
		printf("이름 성별 학번 호실 벌점\n");
		printf("%s [%c] %d %d %d\n", rp->name, rp->fm, rp->entry, rp->room, rp->point);
		
		printf("위 학생에게 벌점을 부여할까요? (YES 1, NO 0) >> ");
		scanf("%d",&YN);
		
		if (YN==1){
		  rp->point++;
		  printf("%s 학생의 벌점은 %d점입니다.\n",rp->name,rp->point);
		}
  }
  else {
    printf("없는 학생입니다.\n");
  }

}
/////////////////////////////////////////////////////////

void find_members(struct Record * p[], int n){
	int i, count=0;
	char name[20];
	while(1){
		printf("검색하려는 학생 이름을 2글자 이상 입력하세요. >> ");
		scanf("%s", name);
		if(strlen(name) > 1) break;
	}
/////////////////////////////
// 여기부터 함수의 기능을 구현할 것!  --> 14-3 문제
  printf("NO 이름 성별 학번 호실 벌점\n");
  for (int i=0;i<n;i++) {
    if (strstr(p[i]->name, name)!=NULL) {
      printf("%d %s [%c] %d %d %d\n",i+1,p[i]->name,p[i]->fm,p[i]->entry,p[i]->room,p[i]->point);
      count++;
    } 
  }
  printf("%d명 검색됨\n",count);
	
}
///////////////////////////////////////////////

void save_report(struct Record* p[], int n){
  int fcount=0;
  int count0=0, count1=0, count2=0;
  int count5=0, count6=0, count7=0, count8=0;
  int person=0, num;
  int zero[40], one[40],two[40], high[40];
// 보고서 저장함수 --> 14-4 문제
	FILE* file1;
	file1 = fopen("report.txt","wt");
	fprintf(file1,"다윗관 현황 보고서\n");
	for (int i=0;i<n;i++) {
	  if (p[i]->fm=='F') fcount++;
	}
	fprintf(file1,"1. 거주학생 수 : 40명 (남 %d명, 여 %d명)\n",40-fcount,fcount);
	
	for (int i=101;i<=215;i++) {
	  num=0;
	  if (i==116) i=201;
	  for (int j=0;j<40;j++) {
	    if (i==p[j]->room) num++;
	  }
	  if (num==0) {
	    zero[count0]=i;
	    count0++;
	  }
	  else if (num==1) {
	    one[count1]=i;
	    count1++;
	  }
	  else if (num==2) {
	    two[count2]=i;
	    count2++;
	  }
	}
	for (int i=0;i<40;i++) {
	  if (p[i]->entry==2015) count5++;
	  else if (p[i]->entry==2016) count6++;
	  else if (p[i]->entry==2017) count7++;
	  else if (p[i]->entry==2018) count8++;
	  
	  if (p[i]->point>=7) {
	    high[person]=i;
	    person++;
	  }
	}
	
	fprintf(file1,"\n2. 호실 현황\n");
	fprintf(file1,"  1) 공실 : ");
	for (int i=0;i<count0;i++) fprintf(file1," %d ",zero[i]);
	fprintf(file1,"\n  2) 1인실 : ");
	for (int i=0;i<count1;i++) fprintf(file1," %d ",one[i]);
	fprintf(file1,"\n  3) 2인실 : ");
	for (int i=0;i<count2;i++) fprintf(file1," %d ",two[i]);
	
	fprintf(file1,"\n\n3. 학번별 현황\n");
	fprintf(file1,"  1) 2015학번: %d명\n",count5);
	fprintf(file1,"  2) 2016학번: %d명\n",count6);
	fprintf(file1,"  3) 2017학번: %d명\n",count7);
	fprintf(file1,"  4) 2018학번: %d명\n",count8);
	
	fprintf(file1,"\n4. 고벌점자(7점 이상) : %d명\n",person);
	for (int i=0;i<person;i++) fprintf(file1,"%s(%d) ",p[high[i]]->name, p[high[i]]->point);
	
	fprintf(file1,"\n\n5. 관생 목록\n");
	fprintf(file1,"NO     이름     성별     학번     호실     벌점\n");
	for (int i=0;i<40;i++) fprintf(file1,"%-7d %-7s   [%c]    %-7d  %-7d  %-7d\n",i+1,p[i]->name,p[i]->fm,p[i]->entry,p[i]->room,p[i]->point);


	fclose(file1);
}	
