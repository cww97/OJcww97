#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 100007;
map <int,int> vis;
vector<int>g[N],G[N];
int ask[N],ans,fa[N],son[N];
void DFS(int x,int dad){
    fa[x] = dad;
    son[x] = 0;
    for (int i= 0;i<g[x].size();i++){
        if (g[x][i]==dad)continue;
        DFS(g[x][i],x);
        son[x]++;
    }
}

int dfs(int x){
    if (vis[x]!=-1) return vis[x];
    int num = 0,sont=0;
    for(int i=0;i<G[x].size();i++)  {
        if( dfs(G[x][i]) >= 1 ) num++;
        sont++;
    }
    int sum = son[x] - sont + num ;
    if (sum>=2){ans++;return vis[x]=2;}
    else if (sum>=1)return vis[x] = 1 ;
    return vis[x] = -2 ;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,n,m,q,x,y;
    scanf("%d",&T);
    for (int cas=0;T--;){
        scanf("%d%d", &n, &q);
        memset(son,0,sizeof(son));
        for (int i=0;i<=n;i++)g[i].clear();
        for (int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        DFS(1,0);
        printf("Case #%d:\n",++cas);
        for (;q--;){
            scanf("%d",&m);
            vis.clear();
            for (int i=1;i<=m;i++){
                scanf("%d",&ask[i]);
                vis[ask[i]] = -1;
                G[ask[i]].clear();
            }
            for (int i=1;i<=m;i++)
                if (vis[fa[ask[i]]]==-1)
                    G[fa[ask[i]]].push_back(ask[i]);
            ans = 0 ;
            for (int i=1;i<=m;i++)
                if (vis[ask[i]]==-1)dfs(ask[i]);
            printf("%d\n",n-m+ans);
        }
    }
    return 0;
}
