#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 2007;
const int INF=0x3f3f3f3f;
const double EPS = 1e-8;
struct MCMF{
    struct Edge{
        int from,to,cap,flow;
        double cost;
        Edge(int x,int y,int z,int u,double v){
            from=x;to=y;cap=z;flow=u;cost=v;
        }
    };
    vector <Edge> edges;
    vector <int > G[N];
    int n, m, s, t;
    int inq[N], p[N], a[N];
    double d[N];

    inline void Init(int n,int s,int t){
        this->n = n;
        this->s = s;
        this->t = t;
        edges.clear();
        for (int i=1;i<=n;i++)G[i].clear();
    }
    inline void AddEdge(int f,int t,int c,double w){
        edges.push_back(Edge(f,t,c,0, w));
        edges.push_back(Edge(t,f,0,0,-w));
        int top = edges.size();
        G[f].push_back(top-2);
        G[t].push_back(top-1);
    }

    bool spfa(int s,int t,int flow,double &cost){
        for (int i=0;i<=n+1;i++)d[i]=INF;
        d[t] = INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
        queue<int>Q;Q.push(s);
        //puts("???");
        for (;!Q.empty();){
                //puts("???");
            int u =Q.front();Q.pop();inq[u]=0;
            for (int i=0;i<G[u].size();i++){
                Edge &e = edges[G[u][i]];
                if (e.cap<=e.flow||d[e.to]<=d[u]+e.cost+EPS)continue;
                d[e.to] = d[u] + e.cost;
                p[e.to] = G[u][i];
                a[e.to] = min(a[u],e.cap-e.flow);
                if (!inq[e.to]){Q.push(e.to);inq[e.to]=1;}
            }
        }
        if (d[t] >= INF)return 0;//false
        flow += a[t];
        cost +=(double)d[t] * (LL)a[t];
        for (int u=t;u!=s;u=edges[p[u]].from){
            edges[p[u]  ].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        return 1;//true
    }

    ///需要保证初始网络中没有负权
    double mcmf(int s,int t){
        int flow =0;
        double cost = 0;
        for (;spfa(s,t,flow,cost);){
            //printf("cost = %.2lf\n",cost);
        }
        return cost;
    }///MinCostMaxFlow
}g;


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w", stdout);
    int T, x, y, z, n, m;
    scanf("%d", &T);
    for (double p; T--;){
        scanf("%d%d", &n, &m);
        g.Init(n, 0, n+1);
        int s = 0, t = n+1;
        for (int i=1; i<=n ;i++){
            scanf("%d%d", &x, &y);
            g.AddEdge(s, i, x, 0.0);
            g.AddEdge(i, t, y, 0.0);
        }
        for (int i=1; i<=m; i++){
            scanf("%d%d%d%lf",&x,&y,&z,&p);
            p = - log(1 - p);
            g.AddEdge(x, y, z-1, p);
            g.AddEdge(x, y,  1 , 0);
        }
        double ans = -g.mcmf(s,t);
        //printf("ans = %.2lf\n",ans);
        printf("%.2lf\n", 1 - exp(ans));
    }
    return 0;
}
