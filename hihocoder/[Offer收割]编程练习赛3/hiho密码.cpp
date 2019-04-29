#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1010;
int n,a[N],key[N],L,R;
bool vis[N];

bool check(int x){
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=x;i++) {
		a[i]=key[i];
		vis[key[i]]=1;
	}
	int st=1,j;
	for (int i=x+1;i<=n;i++){
		for (j=st;j<=n;j++)if (!vis[j])break;
		a[i]=j;
		st=j+1;
		if (j!=key[i])return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){scanf("%d",&key[i]);}
	for (L=0,R=n;L<=R;){
		if (L==R)break;
		int mid=(L+R)>>1;
		if (check(mid))R=mid;
		else L=mid+1;
	}
	if (R){
		for (int i=1;i<R;i++)printf("%d ",key[i]);
		printf("%d\n",key[R]);
	}else puts("1");
	return 0;
}
