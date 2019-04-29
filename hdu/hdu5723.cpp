#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int M=1000007;
const int N=100007;
int m;
ll n;
struct Edge{
    int x,y;
    ll w;
    Edge(){}
    Edge(int a,int b,ll c){x=a;y=b;w=c;}
    bool operator < (const Edge e)const{return w<e.w;}
}edges[M];
vector<int>g[N];
void Link(int x,int y,int e){
    g[x].push_back(e);
    g[y].push_back(e);
}

int f[N];
int F(int x){
    return x==f[x]?x:(f[x]=F(f[x]));
}

int a[N];
bool vis[N];
ll SUM;
void DFS(int x){
    vis[x]=1;
    a[x]+=1;
    for (int i=0;i<g[x].size();i++){
        Edge e=edges[g[x][i]];
        int y;if (e.x==x)y=e.y;else y=e.x;
        if (vis[y])continue;
        DFS(y);
        SUM=SUM+(ll)((ll)(n-a[y])*(ll)(a[y])*e.w);
        a[x]+=a[y];
    }
}

int main(){
	freopen("fuck.in","r",stdin);
	int T,x,y;
	ll z;
	scanf("%d",&T);
	while (T--){
		scanf("%I64d%d",&n,&m);
		for (int i=1;i<=m;i++){
            scanf("%d%d%I64d",&x,&y,&z);
            edges[i]=Edge(x,y,z);
		}
		for (int i=1;i<=n;i++)g[i].clear();

		sort(edges+1,edges+m+1);       //kruskal
        for (int i=1;i<=n;i++)f[i]=i;
        int cnt=0;
        ll sum=0;
        for (int i=1;i<=m;i++){
            int x=edges[i].x;
            int y=edges[i].y;
            if (F(x)==F(y))continue;
            f[f[x]]=F(y);
            cnt++;
            Link(x,y,i);
            sum=sum+edges[i].w;
            if (cnt==n-1)break;
        }

        SUM = 0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        DFS(1);
        double ans=2.0*SUM/(n*(n-1));
        printf("%I64d %.2lf\n",sum,ans);
	}
	return 0;
}
