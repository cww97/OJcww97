#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
using namespace std;
const int N=110;
int n,ans,a[N][N],b[N];
int main(){
  //freopen("fuck.in","r",stdin);
  for (;scanf("%d",&n)==1;){
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	int ans=INT_MIN;
	for (int up=1;up<=n;up++){
	  memset(b,0,sizeof(b));
	  for (int down=up;down<=n;down++)
	  	for (int i=1,sum=0;i<=n;i++){
	  	  b[i]+=a[down][i];
	  	  sum=max(sum+b[i],b[i]);
	  	  ans=max(sum,ans);
	  	}
	}
	printf("%d\n",ans);
  }
  return 0;
}
