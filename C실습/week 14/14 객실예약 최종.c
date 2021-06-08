#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char GRADE[3][10]={"Deluxe", "Luxury", "Sweet"}; // 객실등급 명칭 

struct st_card{		// 객실 관리 카드 레코드
	int no;		// 객실번호 (3자리 숫자)
	int grade; // 객실 등급 (1:deluxe, 2:luxury, 3:sweet)
	int capa;		// 수용최대인원 (2~10명)
	char name[20];	// 예약자 성명				
	int person;		// 예약 인원
};

int load_cards(struct st_card* p[]);		// 객실정보 읽기
void list_cards(struct st_card* p[], int n);	// 객실 목록 출력
void make_reserve(struct st_card* p[], int n);		// 객실 예약
void cancel_reserve(struct st_card* p[], int n);	// 예약 취소
void find_cards(struct st_card* p[], int n);	// 객실 검색
void save_report(struct st_card* p[], int n);	// 보고서 저장
//추가
void find_room(struct st_card* p[], int n);	// 빈 객실 찾기
int add_cards(struct st_card* p[], int n);	// 객실 추가 

int main(){
	struct st_card* cards[50]; 	// 최대 50개의 객실을 관리할 수 있는 구조체 포인터 배열
	int count;	// 현재 등록된 카드 수
	int menu;	// 메뉴번호

	count = load_cards(cards);	// 시작 전에 파일로부터 객실 리스트를 모두 읽어온다.
	while(1)
	{
		// 메뉴 출력
		printf("\n[1]객실목록 [2]예약 [3]예약취소 [4]검색 [5]저장 [6]빈객실찾기 [7]객실추가 [0]종료 >> ");
		scanf("%d",&menu);	// 메뉴를 읽음

		if(menu==1){
			list_cards(cards, count);	// 객실 목록 출력
		}
		else if(menu==2){
			make_reserve(cards, count);	// 예약하기
		}
		else if(menu==3){
			cancel_reserve(cards, count); // 예약 취소
		}
		else if(menu==4){
			find_cards(cards, count);	// 검색
		}
		else if(menu==5){
			save_report(cards, count);	// 보고서 저장
		}
		else if(menu==6){
			find_room(cards, count);	// 빈 객실 찾기
		}
		else if(menu==7){
			count = add_cards(cards, count);	// 객실 추가
		}
		else {
			break;
		}
	}
}

int load_cards(struct st_card* p[]){
	FILE *file;
	int n=0;
	file = fopen("rooms.txt","r");
	while(!feof(file)){
		p[n]=(struct st_card*)malloc(sizeof(struct st_card));
		int result = fscanf(file,"%d %d %d",&(p[n]->no),&(p[n]->grade),&(p[n]->capa));
		if (result < 1) break;
		n++;
	}
	fclose(file);
	printf("%d개의 객실 정보를 읽었습니다.\n",n);
	return n;
}

void list_cards(struct st_card * p[], int n){
	int i;
	printf("\n전체 객실 목록입니다.\n");
	printf("객실번호 / 등급 / 최대인원 / 예약상황\n");
	
	for(i=0; i<n; i++){
		printf("%d호 / %s / %d명 / ", p[i]->no, GRADE[p[i]->grade-1], p[i]->capa);
		if(p[i]->person > 0)
			printf("예약 : %s %d명\n",p[i]->name, p[i]->person);
		else
			printf("예약없음\n");
	}
}

////////// 여기까지는 수정할 필요 없음////////////////////////

void make_reserve(struct st_card* p[], int n){
	char name[20];
	struct st_card* rp; // 예약할 카드레코드 구조체의 포인터값
	int i, roomno, newperson;
	int rmo, canum, res;

	printf("예약하실 고객 이름은? >> ");
	scanf("%s", name);
	printf("예약 인원수를 입력하시오. >> ");
	scanf("%d", &newperson); 
	while (1){
	  rmo=0;
	  canum=0;
	  res=0;
	  printf("예약하실 객실 번호는? >> ");
  	scanf("%d", &roomno);
  	if (roomno<101 || roomno>303 ) rmo=1;
  	else if ((roomno>107 && roomno<201) || (roomno>205 && roomno<301)) rmo=1;
  	
  	for(i=0;i<n;i++){
  		if(p[i]->no==roomno){
  			if (newperson>p[i]->capa) canum=1;
  			if (p[i]->person!=0) res=1;
  			break;
  		}
  	}
  
  	
  	if (rmo==1) printf("예약불가(객실번호 오류)\n");
  	else if (res==1) printf("예약불가(예약된 객실)\n");
  	else if (canum==1) printf("예약불가(인원 초과)\n");
	  else break;
	}
	
	for(i=0;i<n;i++){
		if(p[i]->no==roomno){
			rp=p[i];
			break;
		}
	}
	rp->person = newperson;
	strcpy(rp->name, name);
	printf("예약완료!\n");
}

void cancel_reserve(struct st_card* p[], int n){
  int roomno;
  int YN;
  printf("예약 취소하실 객실 번호는? >> ");
  scanf("%d",&roomno);
  
  for(int i=0;i<n;i++){
		if(p[i]->no==roomno){
			if (p[i]->person==0) printf("예약된 객실이 아닙니다.\n");
			else {
			  printf("객실번호 / 등급 / 예약자 / 예약인원\n");
			  printf("%d호 / %s / %s / %d명\n",p[i]->no,GRADE[p[i]->grade-1],p[i]->name,p[i]->person);
			  printf("위 예약을 취소할까요? (YES 1, NO 0) >> ");
			  scanf("%d",&YN);
			  if (YN==1) {
			    strcpy(p[i]->name,"\0");
			    p[i]->person=0;
			    printf("취소했습니다.\n");
			    break;
			  }
			  else break;
			}
		}
	}
  
}

void find_cards(struct st_card * p[], int n){
  int count=0;
  char name[20];
  char * area;
  while (1) {
    printf("검색하려는 고객 이름을 2글자 이상 입력하세요. >> ");
    scanf("%s",name);
    if (strlen(name)>1) break;
  }
  
  printf("객실번호 / 등급 / 예약자 / 예약인원 / 최대인원\n");
  for (int i=0;i<n;i++) {
    area=strstr(p[i]->name, name);
    if (area != NULL) {
      printf("%d호 / %s / %s / %d명 / %d명\n",p[i]->no,GRADE[p[i]->grade-1],p[i]->name,p[i]->person,p[i]->capa);
      count++;
    }
  }
  
  printf("%d명 검색됨\n",count);
  
}

void save_report(struct st_card* p[], int n){
  int Dnum=0, Lnum=0, Snum=0;
  int Dcount=0, Lcount=0, Scount=0;
  int Dcapa=0, Lcapa=0, Scapa=0;
  int res=0;
  FILE * file1;
  file1=fopen("rooms_reprt.txt","w");
  fprintf(file1,"객실 현황 보고서\n");
  
  for (int i=0;i<n;i++) {
    if (p[i]->grade==1) {
      if (p[i]->person!=0) {
        Dnum++;
        Dcount+=p[i]->person;
      }
      Dcapa+=p[i]->capa;
    }
    else if (p[i]->grade==2) {
      if (p[i]->person!=0) {
        Lnum++;
        Lcount+=p[i]->person;
      }
      Lcapa+=p[i]->capa;
    }
    else if (p[i]->grade==3) {
      if (p[i]->person!=0) {
        Snum++;
        Scount+=p[i]->person;
      }
      Scapa+=p[i]->capa;
    }
  }
  
  fprintf(file1,"\n객실 등급 : Deluxe\n");
  fprintf(file1,"1. 객실 수: 총 3실 중 %d실 예약 중\n",Dnum);
  fprintf(file1,"2. 예약 고객 : 총 %d명\n",Dcount);
  fprintf(file1,"3. 남은 최대수용 고객 : 총 %d명\n",Dcapa-Dcount);
  
  fprintf(file1,"\n객실 등급 : Luxury\n");
  fprintf(file1,"1. 객실 수: 총 8실 중 %d실 예약 중\n",Lnum);
  fprintf(file1,"2. 예약 고객 : 총 %d명\n",Lcount);
  fprintf(file1,"3. 남은 최대수용 고객 : 총 %d명\n",Lcapa-Lcount);
  
  fprintf(file1,"\n객실 등급 : Sweet\n");
  fprintf(file1,"1. 객실 수: 총 3실 중 %d실 예약 중\n",Snum);
  fprintf(file1,"2. 예약 고객 : 총 %d명\n",Scount);
  fprintf(file1,"3. 남은 최대수용 고객 : 총 %d명\n",Scapa-Scount);
  
  fprintf(file1,"\n객실 예약 목록\n");
  fprintf(file1,"객실번호 / 등급 / 최대인원 / 예약상황\n");
  for (int i=0;i<n;i++) {
    fprintf(file1,"%d호 / %s / %d명 / ",p[i]->no,GRADE[p[i]->grade-1],p[i]->capa);
    if (p[i]->person!=0) {
      fprintf(file1,"예약 : %s %d명\n",p[i]->name,p[i]->person);
      res+=p[i]->person;
    }
    else fprintf(file1,"예약없음\n");
  }
  fprintf(file1,"예약 인원 합계 : %d명\n",res);
  fclose(file1);
  printf("저장되었습니다.\n");
}	

void find_room(struct st_card* p[], int n){
  int count=0, roomgd;
  int newperson;
  printf("투숙 인원수는? >> ");
  scanf("%d",&newperson);
  printf("원하시는 객실 등급은? (Deluxe 1, Luxury 2. Sweet 3, 무관 0) >> ");
  scanf("%d",&roomgd);
  printf("객실번호 / 등급 / 최대인원\n");
  
  for (int i=0;i<n;i++) {
    if (roomgd==1) {
      if (i>3) break;
    }
    else if (roomgd==2) {
      if (i==0) i=3;
      if (i>11) break;
    }
    else if (roomgd==3) {
      if (i==0) i=11;
      if (i>n) break;
    }
    if (p[i]->capa>=newperson) {
      printf("%d호 / %s / %d명\n",p[i]->no,GRADE[p[i]->grade-1],p[i]->capa);
      count++;
    }
  }
  printf("총 %d개의 객실이 예약 가능합니다.\n",count);

}

int add_cards(struct st_card* p[], int n){
  int newroom, newgrade, newcapa;
  int next=0;
  while (1) {
    next=0;
    printf("추가할 객실번호는? >> ");
    scanf("%d",&newroom);
    
    for (int i=0;i<n;i++) {
      if (p[i]->no==newroom) {
        printf("이미 등록된 객실번호입니다.\n");
        next=2;
        break;
      }
      if (newroom-1==p[i]->no) next=1;
    }
    if (next==0) printf("연속적인 객실번호가 아닙니다.\n");
    
    if (next==1) {
      printf("객실등급(Deluxe 1, Luxury 2. Sweet 3)과 최대인원을 입력하세요 >> ");
      scanf("%d %d",&newgrade, &newcapa);
      p[n]->no=newroom;
      p[n]->grade=newgrade;
      p[n]->capa=newcapa;
      printf("객실을 추가하였습니다.\n");
      break;
    }
  }
  return n+1;
}