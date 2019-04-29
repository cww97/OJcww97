#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
int t,T,n,q,i,j,l,r,maa,mii;
int ma[100000][50],mi[100000][50];
using namespace std;
int main(){
	freopen("fuck.in","r",stdin);
	memset(mi,1,sizeof(mi));
    scanf("%d%d",&n,&q);
    for (i=1;i<=n;i++){
    	scanf("%d",&ma[i][0]);
    	mi[i][0]=ma[i][0];
    }
    T=ceil(log2(n));
    for (j=1;j<=T;j++)
      for (i=1;i<=n;i++){
      	mi[i][j]=min(mi[i][j-1],mi[i+(1<<j-1)][j-1]);
      	ma[i][j]=max(ma[i][j-1],ma[i+(1<<j-1)][j-1]);
      }
    for (i=1;i<=q;i++)
    {
    	scanf("%d%d",&l,&r);
    	t=floor(log2(r-l+1));
    	maa=max(ma[l][t],ma[r-(1<<t)+1][t]);
    	mii=min(mi[l][t],mi[r-(1<<t)+1][t]);
    	printf("%d\n",maa-mii);
    }
	return 0;
} 
