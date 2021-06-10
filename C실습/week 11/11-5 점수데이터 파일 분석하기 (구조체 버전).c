#include <stdio.h>
#include <string.h>

struct score_struct{
	char name[10]; // 이름 
	int jumsu[3];  // 점수 (C, Java, Python)
	int sum;  // 총점
	float avg;  //  평균 
};

int main(void) {
  int i;
  int subsum[3]={0};
  float subavg[3];
  int max[3], maxi;
  char sub[3][10]={"C","Java","Python"};
  struct score_struct p[10];
  FILE * data;
  data=fopen("data.txt","r");
  
  while (!feof(data)) {
    fscanf(data,"%s %d %d %d",p[i].name,&p[i].jumsu[0],&p[i].jumsu[1],&p[i].jumsu[2]);
    if (p[i].jumsu[0]==0 || p[i].jumsu[1]==0 || p[i].jumsu[2]==0) break;
    i++;
  }
  printf("%d records read.\n",i);
  for (int k=0;k<i;k++) {
    p[k].sum=0;
    for (int j=0;j<3;j++) {
      p[k].sum+=p[k].jumsu[j];
      subsum[j]+=p[k].jumsu[j];
    }
    p[k].avg=p[k].sum/3.0;
    printf("%-5s %-2d %-2d %-2d %-3d %-3.1f\n",p[k].name,p[k].jumsu[0],p[k].jumsu[1],p[k].jumsu[2],p[k].sum, p[k].avg);
  }

  for (int j=0; j<3;j++) {
	  subavg[j]=(float) subsum[j]/i;
	  for (int k=0; k<i;k++) {
	    if (p[k].jumsu[j]>max[j] || k==0) {
	      max[j]=p[k].jumsu[j];
	      maxi=k;
	    }
	  }
	  printf("%-3s - average : %.1f, Top : %s (%d)\n",sub[j], subavg[j], p[maxi].name, p[maxi].jumsu[j]);
	}
	fclose(data);
  


  return 0;
}