#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int ddx[]={-1,-1,1,1};
const int ddy[]={-1,1,-1,1};
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int cnt=0,dia=0,dib=0,k,l,ti,x,y;
int row[5],col[5],g[5][5];

void fuck(){
		for (int i=1;i<=3;i++){
	  for (int j=1;j<3;j++)printf("%d ",g[i][j]);
	  printf("%d\n",g[i][3]);}
}

int main(){
	freopen("fuck.in","r",stdin);
	memset(g,0,sizeof(g));
	for (int i=1;i<=3;i++)
	  for (int j=1;j<=3;j++){
	  	scanf("%d",&g[i][j]);
	  	if (i==2&&j==2)g[2][2]=5;
	  	if (g[i][j]==0)continue;
	  	cnt++;row[i]++;col[j]++;
	  	if (i-j==0)dia++;
	  	if (i+j==4)dib++;
	  }	
    
	for (ti=0;cnt<9;ti++){
		for (int i=0;i<4;i++){
			x=2+ddx[i],y=2+ddy[i];
			int s=0,cntt=0;
			for (int j=0;j<4;j++){
				int cx=x+dx[j],cy=y+dy[j];
				s+=g[cx][cy];
				if (g[cx][cy])cntt++;
			}
			if (cntt==2){
				if (s== 4)g[x][y]=8;
				if (s==12)g[x][y]=4;
				if (s==16)g[x][y]=2;
				if (s== 8)g[x][y]=6;
				//fuck();
				cnt++;row[x]++;col[y];
				if (x==y)dia++;
				if (x+4==4)dib++;
			}
		}
		if (dia==2){
			int sum=0;
			for (int j=1;j<=3;j++){
				sum+=g[j][j];
			    if (!g[j][j])k=j;
			}
			g[k][k]=15-sum;
			cnt++;dia++;
			row[k]++;col[k]++;
		}
		if (dib==2){
			int sum=0;
			for (int j=1;j<=3;j++){
				sum+=g[j][4-j];
				if (!g[j][4-j])k=j;
			}
			g[k][4-k]=15-sum;
			cnt++;dib++;
			row[k]++;col[4-k]++;
		}
		for (int j=1;j<=3;j++){
			if (row[j]==2){
				int sum=0;
				for (int k=1;k<=3;k++){
					sum+=g[j][k];
					if (!g[j][k])l=k;
				}
				g[j][l]=15-sum;
				if (j==l)dia++;
				if (j+l==4)dib++;
				cnt++;row[j]++;col[l]++;
			}
		}
		for (int j=1;j<=3;j++){
			if (col[j]==2){
				int sum=0;
				for (int k=1;k<=3;k++){
					sum+=g[k][j];
					if (!g[k][j])l=k;
				}
				g[l][j]=15-sum;
				if (l==j)dia++;
				if (l+j==4)dib++;
				cnt++;row[l]++;col[j]++;
			}
		}
		if (ti==20)break;
	}
	if (cnt<9)puts("Too Many");
	else fuck();
	return 0;
} 
