#include<cstdio>
#include<cmath> 
#include<cstring>
using namespace std;
const int N=100007;
bool vis[N<<1];
int ax[N],ay[N];
int n,m;

bool work(){
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
		scanf("%d%d",&ax[i],&ay[i]);
	for (int i=1;i<=n;i++)if(ax[i]<=m&&ay[i]<=m){
		for (int j=1;j<i;j++)if(ax[j]<=m||ay[j]<=m){
			int d=abs(ax[i]-ax[j])+abs(ay[i]-ay[j]);
			if (vis[d])return 1;
			else vis[d]=1;
		}
	}
	return 0;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		if (work())puts("YES");
		else puts("NO");
	}
	return 0;
} 
