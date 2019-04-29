#include<stdio.h>
int main(){
	int i,j,k,stu;
	double sco[50][5],avg1[50],avg2[5],n,m;
	while(scanf("%lf%lf",&n,&m)!=EOF&&n<=50&&m<=5){
		for(i=0;i<n;i++){
			avg1[i]=0;
			for(j=0;j<m;j++){
				scanf("%lf",&sco[i][j]);
				avg1[i]+=sco[i][j];
			}
			avg1[i]/=m;
		}
		for(k=0,i=0;i<n;i++){
			if(k!=0)printf(" ");
			printf("%.2lf",avg1[i]);
			k++;
		}printf("\n");
		for(k=0,j=0;j<m;j++){
			avg2[j]=0;
			for(i=0;i<n;i++)
				avg2[j]+=sco[i][j];
			avg2[j]/=n;
			if(k!=0)printf(" ");
			printf("%.2lf",avg2[j]);
			k++;
		}printf("\n");
		for(stu=0,i=0;i<n;i++){
			for(k=0,j=0;j<m;j++)
				if(sco[i][j]>=avg2[j])k++;
			if(k==m)stu++;
		}
		printf("%d\n\n",stu);			
	}
}
