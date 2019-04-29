#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10007;
int s[110],sg[N],k;

void getSG(){
	sg[0]=0;
	bool vis[N];
	for (int i=1;i<N;i++){
		memset(vis,0,sizeof(vis));
		for (int j=1;s[j]<=i&&j<=k;j++)vis[sg[i-s[j]]]=1;
		for (int j=0;j<N;j++)if(!vis[j]){sg[i]=j;break;}
	}
}

int main(){
	//freopen("fuck.in","r",stdin);
	int m,n,x;
	while (scanf("%d",&k)==1&&k){
		for (int i=1;i<=k;i++)scanf("%d",&s[i]);
		sort(s+1,s+k+1);
		getSG();
		scanf("%d",&n);
		while (n--){
			scanf("%d",&m);
			int ans=0;
			while (m--){
				scanf("%d",&x);
				ans ^= sg[x];
			}
			putchar(ans?'W':'L');
		}
		puts("");
	}
	return 0;
} 
