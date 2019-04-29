#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<fstream>
//
#define INF 2147483647
using namespace std;

int st[1000010][21];
int st2[1000010][21];

int makest(int n){
	for (int j=1;j<=20;j++){
		//printf("---->%d\n",n+1-(1<<j));
		for(int i=1;i<=n+1-(1<<j);i++){
			//printf("--->st[%d][%d]=%d,st[%d][%d]=%d\n",i,j-1,st[i][j-1],i+(1<<j-1),j-1,st[i+(1<<j-1)][j-1]);
			st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
			//printf("i=%d,j=%d,st=%d\n",i,j,st[i][j]);
		}
	}
	for (int j=1;j<=20;j++){
		//printf("---->%d\n",n+1-(1<<j));
		for(int i=1;i<=n+1-(1<<j);i++){
			//printf("--->st[%d][%d]=%d,st[%d][%d]=%d\n",i,j-1,st[i][j-1],i+(1<<j-1),j-1,st[i+(1<<j-1)][j-1]);
			st2[i][j]=max(st2[i][j-1],st2[i+(1<<j-1)][j-1]);
			//printf("i=%d,j=%d,st=%d\n",i,j,st[i][j]);
		}
	}
	return 0;
}

int find(int l,int r){
	int k=r-l+1;
	int i=0;
	while ((1<<i+1)<k) i++;
	int Min=min(st[l][i],st[r+1-(1<<i)][i]);
	k=r-l+1;
	i=0;
	while ((1<<i+1)<k) i++;
	int Max=max(st2[l][i],st2[r+1-(1<<i)][i]);
	return Max-Min;
}

int n,m;

int main(){
	//freopen("st.in","r",stdin);
	//freopen("st.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&st[i][0]);
	for (int i=1;i<=n;i++) st2[i][0]=st[i][0];
	makest(n);
	/*for(int j=3;j>=0;j--){
		for (int i=1;i<=n;i++){
			printf("%d ",st[i][j]);
		}
		printf("  --->%d\n",n+1-(1<<j));
	}
	for(int j=3;j>=0;j--){
		for (int i=1;i<=n;i++){
			printf("%d ",st2[i][j]);
		}
		printf("  --->%d\n",n+1-(1<<j));
	}*/
	while (m--){
		int l,r;
		scanf("%d%d",&l,&r);
		int f=find(l,r);
		printf("%d\n",f);
	}
	
	
	
	
return 0;
}
