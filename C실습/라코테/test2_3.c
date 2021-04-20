#include <stdio.h>
#include <string.h>
/*
1. 문자열은 입력받기 

2. 빈칸은 _ 문자로 바꾸기

3. 소문자는 대문자로 바꾸기
    3-1. 소문자 --> 대문자 == 해당문자 +(대문자-소문자 간격)

4. 대문자는 소문자로 바꾸기 
    4-1. 대문자 --> 소문자 == 해당문자 - (대문자 -소문자 간격);

5. 숫자는 해당 문자로 변경하기 
   숫자== 일때 해당 문자로 바꾸기 

6. 나머지는 제거 

7. 해당 될때 마다 갯수 세기 

8. 바뀐 문자열 길이 구하기 

*/


int main(void) {
  int i;
  int a,b;
  int count=0;
	char line1[80], line2[80];
	
	printf("line1 > ");
	fgets(line1, 80, stdin);
	line1[strlen(line1)-1]='\0';
	a=strlen(line1);
	
	for (i=0;i<=a;i++) {
	  if (line1[i]==' ') line2[count]='_';
	  else if (line1[i]<='z' && line1[i]>='a') line2[count]=line1[i]+('A'-'a'); // 소문자면 대문자
	  else if (line1[i]>='A' && line1[i]<='Z') line2[count]=line1[i]-('A'-'a'); // 대문자면 소문자
	  else if (line1[i]=='1') line2[count]='!';
	  else if (line1[i]=='2') line2[count]='@';
	  else if (line1[i]=='3') line2[count]='#';
	  else if (line1[i]=='4') line2[count]='$';
	  else if (line1[i]=='5') line2[count]='%';
	  else if (line1[i]=='6') line2[count]='^';
	  else if (line1[i]=='7') line2[count]='&';
	  else if (line1[i]=='8') line2[count]='*';
	  else if (line1[i]=='9') line2[count]='(';
	  else if (line1[i]=='0') line2[count]=')';
	  else count--;
	  count++;
	 
	}
	b=strlen(line2);
	
	printf("line2 > %s ( length : %d )",line2,b);
	


	
	return 0;
}