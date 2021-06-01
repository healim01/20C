#include <stdio.h>

int main(void) {
	char pname[3][10]={"C", "Java", "Python"};
	char name[20][30]; // 이름 (최대 20명)
	int score[3][20]; // 3과목 점수 (최대 20명)
	int sum[20]={0}; // 총점 (최대 20명)
	float avg[20]; // 평균 (최대 20명)
	int i=0;
	int maxi;
	int max[3];
	int subsum[3]={0};
	float subavg[3];
	
	FILE * data;
	data=fopen("data.txt","r");
	while (!feof(data)) {
	  fscanf(data,"%s %d %d %d",name[i],&score[0][i],&score[1][i],&score[2][i]);
	  if (i>20) break;
	  sum[i]+=score[0][i]+score[1][i]+score[2][i];
	  for (int j=0;j<3;j++) subsum[j]+=score[j][i];
	  avg[i]=sum[i]/3.0;
	  i++;
	}
	printf("%d records read.\n",i);
	for (int j=0;j<i;j++) {
	  printf("%-5s %3d %3d %3d %3d %3.1f\n",name[j],score[0][j],score[1][j],score[2][j],sum[j],avg[j]);
	}
	
	for (int j=0; j<3;j++) {
	  subavg[j]=(float) subsum[j]/i;
	  for (int k=0; k<i;k++) {
	    if (score[j][k]>max[j] || k==0) {
	      max[j]=score[j][k];
	      maxi=k;
	    }
	  }
	  printf("%-3s - average : %.1f, Top : %s (%d)\n",pname[j],subavg[j],name[maxi],score[j][maxi]);
	}
	fclose(data);
  return 0;
}