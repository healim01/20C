#include <stdio.h>

int main(void) {
  int h,m;
  int best=0, besti=0, yn;
  int shour[8]={7,9,10,11,12,14,15,16};
  int smin[8]={17,45,15,5,35,00,30,23};
  int fhour[8]={9,12,12,13,15,16,17,18};
  int fmin[8]={51,06,41,33,05,34,53,55};
  int price[8]={4800,53600,53600,53600,48000,53600,53600,53600};
  int name[8]={454,456,458,460,462,464,466,468};

  printf("입력 (서울역에 도착하여야하는 하는 최소한의 시간, 분 입력) :");
  scanf("%d %d",&h,&m);

  for (int i=0;i<8;i++) {
    yn=0;
    if (fhour[i]<=h) {
      if (fhour[i]==h) {
        if (fmin[i]>m) yn=1;
      } 
      if (fhour[i] > best && yn==0) {
        best=fhour[i];
        besti=i;
      }
      if (fhour[i]==best && yn==0) {
        if (fmin[i]>fmin[besti]) {
          besti=i;
        }
      }
    }
  }

  printf("출력 (열차의 포항 출발시간, 가격 및 열차번호) : %d:%d %d KTX%d",shour[besti],smin[besti],price[besti],name[besti]);

  return 0;
}