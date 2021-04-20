#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_book{
	int category; // 분류코드 (0:전공, 1:교양, 2:취미)
	char title[100];  // 도서명
	char pub[100]; // 출판사
	int year;  // 출간년도
	int status; // 상태코드 (0:보관, 1:대여, 2:분실)
	char borrower[100]; // 대여자명
};
char CATEGORY[3][20] = {"전공","교양","취미"};
char STATUS[3][20] = {"보관","대여","분실"};


int load_books(struct st_book* list[]);		// 도서정보 읽어오기
void view_library(struct st_book* list[], int n);	// 현재 서재 정보 출력하기
void add_book(struct st_book* list[], int* n);		// 도서 추가하기
void lost_book(struct st_book* list[], int n);	// 도서 분실 처리하기
void find_books(struct st_book* list[], int n);	// 도서 검색
void update_book(struct st_book* list[], int n);	// 도서정보 수정하기
void save_report(struct st_book* list[], int n);	// 서재 정보 보고서 만들기

int main(){
	struct st_book* my_library[50]; 	// 최대 50개의 객실을 관리할 수 있는 구조체 포인터 배열
	int count;	// 현재 등록된 카드 수
	int menu;	// 메뉴번호
	printf("\n서재 정보입니다.\n");

	count = load_books(my_library);	// 도서정보 읽어오기
	while(1)
	{
		// 메뉴 출력
		printf("\n[1]목록 [2]추가 [3]분실 [4]검색 [5]수정 [6]저장 [0]종료 >> ");
		scanf("%d",&menu);	// 메뉴를 읽음

		if(menu==1){
			view_library(my_library, count);	// 현재 서재 정보 출력하기
		}
		else if(menu==2){
			add_book(my_library, &count);	// 도서 추가하기
		}
		else if(menu==3){
			lost_book(my_library, count); // 도서 분실 처리하기
		}
		else if(menu==4){
			find_books(my_library, count);	// 도서 검색
		}
		else if(menu==5){
			update_book(my_library, count);	// 도서정보 수정하기
		}
		else if(menu==6){
			save_report(my_library, count);	// 서재 정보 보고서 만들기
		}
		else {
			break;
		}
	}
}

int load_books(struct st_book* list[]){
	FILE *file;
	int n=0;
	char bookname[100];
	char line[100];
	file = fopen("books.txt","r");
	while(!feof(file)){
		if(!fgets(bookname, 100, file)) break;
		list[n]=(struct st_book*)malloc(sizeof(struct st_book));
		bookname[strlen(bookname)-1]='\0';
		strcpy(list[n]->title, bookname);
		fgets(line, 100, file);
		sscanf(line,"%d %s %d",&(list[n]->category),list[n]->pub,&(list[n]->year));
		list[n]->status=0;
		n++;
	}
	fclose(file);
	printf("%d개의 도서 정보를 읽었습니다.\n",n);
	return n;
}

void view_library(struct st_book* list[], int n){
	int i;
	printf("\n서재 정보입니다. (총 %d권)\n", n);
	printf("번호 / 분류 / 도서명 / 출판사 / 출간년도 / 상태\n");
	
	for(i=0; i<n; i++){
		printf("%2d / ", i+1);
		printf("%s / ", CATEGORY[list[i]->category]);
		printf("%s / ", list[i]->title);
		printf("%s / ", list[i]->pub);
		printf("%d년 / ", list[i]->year);
		printf("%s ", STATUS[list[i]->status]);
		if(list[i]->status==1) printf("(%s)", list[i]->borrower);
		printf("\n");
	}
}

////////// 여기부터 코드 작성 ////////////////////////

void add_book(struct st_book* list[], int* n){

  list[*n]=malloc(sizeof(struct st_book));
  printf("추가할 도서의 분류 코드(전공 0, 교양 1, 취미 2)를 입력하세요 >> ");
  scanf("%d",&list[*n]->category);
  getchar();
  printf("추가할 도서명을 입력 >> ");
  fgets(list[*n]->title,100,stdin);
  list[*n]->title[strlen(list[*n]->title)-1]='\0';
  printf("출판사를 입력 >> ");
  fgets(list[*n]->pub,100,stdin);
  list[*n]->pub[strlen(list[*n]->pub)-1]='\0';
  
  printf("출간년도를 입력 >> ");
  scanf("%d",&list[*n]->year);
  list[*n]->status=0;
  printf("새로운 도서를 추가하였습니다.\n");

  *n=*n+1;
}

void lost_book(struct st_book* list[], int n){
  int lostnum;
  int YN;

  printf("분실한 도서의 도서번호를 입력하세요 >> ");
  scanf("%d",&lostnum);
  if (lostnum>n || lostnum<0) printf("해당 도서가 존재하지 않습니다.\n");
  else {
    printf("%s / %s / %s / %d\n",CATEGORY[list[lostnum-1]->category],list[lostnum-1]->title,list[lostnum-1]->pub,list[lostnum-1]->year);
    printf("해당 도서를 분실 처리하겠습니까? ( YES 1, NO 0 ) >> ");
    scanf("%d",&YN);
    if (YN==1) {
      list[lostnum-1]->status=2;
      printf("분실 신청되었습니다.\n");
    }
  }

}

void find_books(struct st_book * list[], int n){
  int num;
  char searchname[100], searchpub[100];
  int searchyear, searchcata, searchsta;
  int count=0;
  printf("검색하고 싶은 방법을 선택하세요\n(도서 이름 1, 출판사 이름 2, 출간년도 3, 도서 상태 4, 카테고리 5) >> ");
  scanf("%d", &num);
  getchar();

  if (num==1) {
    while (1) {
      printf("검색하고 싶은 도서 이름의 일부(2글자 이상)를 입력하세요 >> ");
      fgets(searchname,100,stdin);
      searchname[strlen(searchname)-1]='\0';
      if (strlen(searchname)>1) break;
    }
    printf("\n\"%s\"의 도서를 검색하였습니다.\n",searchname);
    printf("번호 / 분류 /  도서명  / 출판사 / 출간년도 / 상태\n");
    for (int i=0;i<n;i++) {
      if (strstr(list[i]->title, searchname)!='\0') {
        printf("%2d / %s / %s / %s / %d / %s \n",i+1,CATEGORY[list[i]->category],list[i]->title,list[i]->pub,list[i]->year,STATUS[list[i]->status]);
        count++;
      }
    }
    printf("%d개의 책을 찾았습니다.\n",count);
  }

  else if (num==2) {
    while (1) {
      printf("검색하고 싶은 도서의 출판사 이름의 일부(2글자 이상)를 입력하세요 >> ");
      fgets(searchpub,100,stdin);
      searchpub[strlen(searchpub)-1]='\0';
      if (strlen(searchpub)>1) break;
    }
    printf("\n\"%s\" 출판사의 도서를 검색하였습니다.\n",searchpub);
    printf("번호 / 분류 /  도서명  / 출판사 / 출간년도 / 상태\n");
    for (int i=0;i<n;i++) {
      if (strstr(list[i]->pub, searchpub)!='\0') {
        printf("%2d / %s / %s / %s / %d / %s\n",i+1,CATEGORY[list[i]->category],list[i]->title,list[i]->pub,list[i]->year,STATUS[list[i]->status]);
        count++;
      }
    }
    printf("%d개의 책을 찾았습니다.\n",count);
  }

  else if (num==3) {
    printf("검색하고 싶은 도서의 출간년도를 입력하세요 >> ");
    scanf("%d",&searchyear);
    printf("\n\"%d\"년도의 도서를 검색하였습니다.\n",searchyear);
    printf("번호 / 분류 /  도서명  / 출판사 / 출간년도 / 상태 \n");
    for (int i=0;i<n;i++) {
      if (list[i]->year==searchyear) {
        printf("%2d / %s / %s / %s / %d /%s \n",i+1,CATEGORY[list[i]->category],list[i]->title,list[i]->pub,list[i]->year,STATUS[list[i]->status]);
        count++;
      }
    }
    printf("%d개의 책을 찾았습니다.\n",count);
  }

  else if (num==4) {
    printf("검색하고 싶은 도서 상태를 입력하세요 (보관 1, 대여 2, 분실 3) >> ");
    scanf("%d",&searchsta);
    printf("\n\"%s\" 상태의 도서를 검색하였습니다.\n",STATUS[searchsta-1]);
    printf("번호 / 분류 /  도서명  / 출판사 / 출간년도 / 상태 \n");
    for (int i=0;i<n;i++) {
      if (list[i]->status==searchsta-1) {
        printf("%2d / %s / %s / %s / %d /%s \n",i+1,CATEGORY[list[i]->category],list[i]->title,list[i]->pub,list[i]->year,STATUS[list[i]->status]);
        count++;
      }
    }
    printf("%d개의 책을 찾았습니다.\n",count);
  }
  
  else if (num==5) {
    printf("검색하고 싶은 도서의 카테고리를 입력하세요 (전공 1, 교양 2, 취미 3) >> ");
    scanf("%d",&searchcata);
    printf("\n\"%s\" 카테고리의 도서를 검색하였습니다.\n",CATEGORY[searchcata-1]);
    printf("번호 / 분류 /  도서명  / 출판사 / 출간년도 / 상태 \n");
    for (int i=0;i<n;i++) {
      if (list[i]->category==searchcata-1) {
        printf("%2d / %s / %s / %s / %d / %s \n",i+1,CATEGORY[list[i]->category],list[i]->title,list[i]->pub,list[i]->year,STATUS[list[i]->status]);
        count++;
      }
    }
    printf("%d개의 책을 찾았습니다.\n",count);
  }
  else printf(" ");
}


void update_book(struct st_book* list[], int n){
  int num;
  int type;

  printf("정보를 수정하고 싶은 도서의 번호를 입력하세요 >> ");
  scanf("%d",&num);
  num--;
  printf("%2d / %s / %s / %s / %d \n",num+1,CATEGORY[list[num]->category],list[num]->title,list[num]->pub,list[num]->year);
  printf("수정하고 싶은 기능을 선택하세요\n(도서 정보 수정 1, 도서 대여 처리 2, 도서 반납 처리 3) >> ");
  scanf("%d",&type);
  getchar();

  if (type==1) {
    printf("수정할 새로운 도서명을 입력 >> ");
    fgets(list[num]->title,100,stdin);
    list[num]->title[strlen(list[num]->title)-1]='\0';
    printf("수정할 새로운 출판사를 입력 >> ");
    fgets(list[num]->pub,100,stdin);
    list[num]->pub[strlen(list[num]->pub)-1]='\0';
    printf("수정할 새로운 출간년도를 입력 >> ");
    scanf("%d",&list[num]->year);
    list[num]->status=0;
    printf("수정할 새로운 도서의 분류 코드(전공 0, 교양 1, 취미 2)를 입력하세요 >> ");
    scanf("%d",&list[num]->category);
    getchar();

    printf("새로운 정보로 수정하였습니다.\n");
  }

  else if (type==2) {
    if (list[num]->status!=0) printf("해당 책은 대여하실 수 없습니다.\n");
    else {
      printf("대여하실 분의 이름을 입력하세요 >> ");
      scanf("%s",list[num]->borrower);
      list[num]->status=1;
      printf("대여 처리 되었습니다.\n");
    }
  }

  else if (type==3) {
    if (list[num]->status!=1) printf("해당 책은 반납하실 수 없습니다.\n");
    else {
      list[num]->status=0;
      strcpy(list[num]->borrower,"\0");
      printf("반납 처리 되었습니다.\n");
    }
  }
}

void save_report(struct st_book* list[], int n){
  int cate[3]={0};
  int stat[3]={0};
  FILE * file1;
  file1=fopen("library.txt","w");

  fprintf(file1,"서재 정보\n");

  fprintf(file1,"\n1. 전체 도서 갯수\n");
  fprintf(file1,"  총 %d권\n",n);
  fprintf(file1,"\n2. 모든 도서 정보\n");
  fprintf(file1,"번호 / 분류 / 도서명 / 출판사 / 출간년도 / 보관\n");
  
  for(int i=0; i<n; i++){
		fprintf(file1,"%2d / ", i+1);
		fprintf(file1,"%s / ", CATEGORY[list[i]->category]);
		fprintf(file1,"%s / ", list[i]->title);
		fprintf(file1,"%s / ", list[i]->pub);
		fprintf(file1,"%d년 / ", list[i]->year);
		fprintf(file1,"%s ", STATUS[list[i]->status]);
		if(list[i]->status==1) fprintf(file1,"(%s)", list[i]->borrower);
		fprintf(file1,"\n");
	}

  for (int i=0;i<n;i++) {
    for (int j=0;j<3;j++) {
      if (list[i]->category==j) cate[j]++;
      if (list[i]->status==j) stat[j]++;
    }
  }

  fprintf(file1,"\n3. 분류별 도서 갯수\n");
  fprintf(file1,"  전공 : %d권\n  교양 : %d권\n  취미 : %d권\n",cate[0],cate[1],cate[2]);
  fprintf(file1,"\n4. 상태별 도서 갯수\n");
  fprintf(file1,"  보관 : %d권\n  대여 : %d권\n  분실 : %d권\n",stat[0],stat[1],stat[2]);

  printf("현재 서재 정보를 저장하였습니다.\n");



  fclose(file1);

}	                                   