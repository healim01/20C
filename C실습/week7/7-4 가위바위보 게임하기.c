#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 시작 : 시 분
// 마침 : 시 분
// 걸린시간 : ?시간 ?분
int main(void) {
  int com_finger; // 컴퓨터가 낸 가위(1), 바위(2), 보(3)
  int my_finger; // 사용자가 낸 가위(1), 바위(2), 보(3)
  int score[2][3]={0}; // 결과 횟수 (1행 : 컴퓨터의 승, 무, 패, 2행 : 사용자의 승, 무, 패)
  int i, j; // 반복문을 위한 변수 
  srand(time(0));
  while (1) {
    com_finger=rand()%3+1;
    printf("가위(1), 바위(2), 보(3)를 입력하세요.");
    scanf("%d",&my_finger);
    if (my_finger==0) break;
    printf("컴퓨터: ");
    if (com_finger==1) printf("가위");
    else if (com_finger==2) printf("바위");
    else printf("보");
    
    if ((com_finger==1 && my_finger==2) || (com_finger==2 && my_finger==3) || (com_finger==3 && my_finger==1)) {
      printf(" -> 사용자 승\n");
      score[0][2]++;
      score[1][0]++;
    }// 사용자 승 : 보-가위 , 가위-바위, 바위-보
    else if ((com_finger==1 && my_finger==3) || (com_finger==2 && my_finger==1) || (com_finger==3 && my_finger==2)) {
      printf("-> 사용자 패\n");
      score[0][0]++;
      score[1][2]++;
    }// 사용자 패 : 보-바위 , 가위-보, 바위-가위
    else {
      printf("-> 비김\n");
      score[0][1]++;
      score[1][1]++;
    }// 비김 : 보-보, 가위-가위 , 바위-바위
    printf("\n");
  }
  
  printf("\n컴퓨터: 이긴 횟수 %d회, 진 횟수 %d회, 비긴 횟수 %d회\n",score[0][0],score[0][2],score[0][1]);
  printf("사용자: 이긴 횟수 %d회, 진 횟수 %d회, 비긴 횟수 %d회\n",score[1][0],score[1][2],score[1][1]);
  
  return 0;
}