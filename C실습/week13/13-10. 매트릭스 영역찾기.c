#include <stdio.h>
void markarea(int p[5][5], int z[5][5], int xpos, int ypos, int area, int value);
// 원본매트릭스(p)의 xpos, ypos 칸으로부터 출발하여 사방을 뒤지면서, value값과 일치하는 칸에 대해 영역매트릭스(z)에 영역번호(area)를 마크하라.

void printmat(int p[5][5]);
// 5*5 매트릭스의 내용을 출력하는 함수 

int main(void) {
  int picture[5][5]={0}; // 원본 패턴 
  int zone[5][5] = {0}; // 영역표시용 패턴
	int row=5, col=5;  // 가로, 세로 크기
	int area=0;  // 영역번호
  FILE *fp;
  
  fp = fopen("picture.txt", "rt");
  for(int i= 0; i < row; i++){
    for(int j= 0; j < col; j++)
      fscanf(fp, "%d", &picture[i][j]);
  }
  fclose(fp);

	printmat(picture);
	printf("\n");

  for(int i=0; i < row; i++){
    for(int j=0; j < col; j++){
    	if(picture[i][j] != 0 && zone[i][j]==0){ // 원본 패턴값이 0이 아니고, 아직 영역체크가 안된 경우
      	area++; // 새로운 영역 시작
				int value=picture[i][j]; // 패턴값
      	markarea(picture, zone, i, j, area, value); // 이 칸으로부터 같은 패턴값의 모든 영역을 찾아 마크하라.
      }
    }
  }
  
	printf("\n%d areas found.\n\n", area);
	printmat(zone);
}  

void printmat(int p[5][5]){
  for(int i=0; i < 5; i++){
    for(int j=0; j < 5; j++){
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }	
}

void markarea(int p[5][5], int z[5][5], int xpos, int ypos, int area, int value){
  if (p[xpos][ypos]==value && z[xpos][ypos]==0) {
    z[xpos][ypos]=area;
    
    if (xpos!=0) markarea(p, z, xpos-1, ypos, area, value);
    if (xpos!=4) markarea(p, z, xpos+1, ypos, area, value);
    if (ypos!=0) markarea(p, z, xpos, ypos-1, area, value);
    if (ypos!=4) markarea(p, z, xpos, ypos+1, area, value);
  }

}