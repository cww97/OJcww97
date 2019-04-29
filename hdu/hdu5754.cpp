#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N=1007;
int  h[N][N];
bool q[N][N];

void Init(){
	memset(h,0,sizeof(h));
	for (int i=1;i<N-5;i+=3){
		h[i][i]=-1;
		h[i+2][i+1]=h[i+1][i+2]=1;
	}
	
	memset(q,1,sizeof(q));
	for (int i=1,j=1;max(i,j)<N-5;i+=2,j++)q[i][j]=0;
	for (int i=1,j=1;max(i,j)<N-5;i++,j+=2)q[i][j]=0;
} 

double phi = (1 + sqrt(5)) / 2.0;
void debug(){
	for (int i=1;i<=30;i++){
		for (int j=1;j<=30;j++){
			bool ok=((min(i-1, j-1) != (int)(phi*abs(i-j))));
			if (ok!=q[i][j])printf("[%d][%d]->%d\n",i,j,ok);
		}
	}
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T,type,n,m;
	scanf("%d",&T);
	Init();
	//debug();
	while (T--){
		scanf("%d%d%d",&type,&n,&m);
		if (type==1) puts((n&m&1)?"G":"B");
		if (type==2) puts((n==m )?"G":"B");
		if (type==3){
			if (h[n][m]== 0)puts("D");
			if (h[n][m]== 1)puts("B");
			if (h[n][m]==-1)puts("G");
		}
		if (type==4){
			puts((min(n-1,m-1)!=(int)(phi*abs(n-m)))?"B":"G");
		}//puts((q[n][m])?"B":"G");
	}
	return 0;
} 
