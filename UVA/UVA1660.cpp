#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N = 9999 ;

struct Dinic
{
    struct Edge{
        int from,to,cap,flow,nxt;
        Edge(){}
        Edge(int u,int v,int c,int f,int n):
            from(u),to(v),cap(c),flow(f),nxt(n){}
    }edges[N], eFork[N];
    int n, s, t, E, head[N];
    bool vis[N]; //use when bfs
    int d[N],cur[N];//dist,now edge,use in dfs
    inline void AddEdge(int f,int t,int c){
        edges[++E] = Edge(f,t,c,0,head[f]);
        head[f] = E;
        edges[++E] = Edge(t,f,0,0,head[t]);
        head[t] = E;
    }
    inline void Init(int n,int s){
        this -> n = n ; E = -1;
        this -> s = s ;
        memset(head,-1,sizeof(head));
    }

    inline bool BFS(){
        memset(vis,0,sizeof(vis));
        queue<int >Q;
        d[s] = 0; vis[s] = 1;
        for (Q.push(s);!Q.empty();){
            int x = Q.front(); Q.pop();
            for (int nxt,i = head[x];i!=-1;i = nxt){
                Edge &e = edges[i]; nxt = e.nxt;
                if (vis[e.to]||e.cap<=e.flow)continue;
                vis[e.to]=1;
                d[e.to]=d[x]+1;
                Q.push(e.to);
            }
        }
        return vis[t];
    }
    inline int DFS(const int& x,int a){
        if (x==t||a==0){return a;}
        int flow = 0, f, nxt;
        for (int& i=cur[x];i!=-1;i=nxt){
            Edge& e = edges[i]; nxt = e.nxt;
            if (d[x]+1!=d[e.to])continue;
            if ((f=DFS(e.to,min(a,e.cap-e.flow)))<=0)continue;
            e.flow += f;
            edges[i^1].flow-=f;//ϲߍ
            flow+=f; a-=f;
            if (!a) break;
        }
        return flow;
    }
    inline int maxFlow(){return maxFlow(s,t);}
    inline int maxFlow(int s, int t){
        //printf("T=%d\n", t);
        int flow = 0;
        for (;BFS();){
            for (int i=0;i<=n;i++)cur[i]=head[i];
            flow += DFS(s,INF) ;
        }
        return flow;
    }
} g ;

int main(){
    //freopen("in.txt","r",stdin);
    int n, m, x, y;
    for (;~scanf("%d%d", &n, &m);){
        g.Init(n*2+2, n);
        for (int i=0; i<n; i++)
            g.AddEdge(i, i+n, 1);
        for (; m--; ){
            scanf(" (%d,%d)",&x,&y);
            g.AddEdge(x+n,y,INF);
            g.AddEdge(y+n,x,INF);
        }
        for (int i=0; i<=g.E; i++)g.eFork[i] = g.edges[i];
        int ans = n;
        for (g.t=1; g.t<n; g.t++){
            for (int j=0; j<=g.E; j++)g.edges[j] = g.eFork[j];
            ans = min(ans,g.maxFlow());
        }
        printf("%d\n",ans);
    }
    return 0;
}
