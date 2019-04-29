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
const double EPS = 1e-6;
struct MCMF{
    struct Edge{
        int from,to,cap,flow,nxt;
        double cost;
        Edge(){}
        Edge(int x,int y,int z,int u,double v,int n){
            from=x;to=y;cap=z;flow=u;cost=v;nxt=n;
        }
    }edges[N];
    int E,head[N];
    int n,s,t,inq[N],p[N],a[N];
    double d[N];

    inline void Init(int n,int s,int t){
        this->n = n; E = -1;
        this->s = s; this->t = t;
        memset(head,-1,sizeof(head));
    }
    inline void AddEdge(int f,int t,int c,double w){
        edges[++E] = Edge(f,t,c,0, w,head[f]);
        head[f] = E;
        edges[++E] = Edge(t,f,0,0,-w,head[t]);
        head[t] = E;
    }

    bool spfa(int s,int t,int flow,double &cost){
        for (int i=0;i<=n;i++)d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
        queue<int>Q;Q.push(s);
        for (;!Q.empty();){
            int nxt, u =Q.front();Q.pop();inq[u]=0;
            for (int i=head[u];i!=-1;i=nxt){
                Edge &e = edges[i]; nxt = e.nxt;
                if (e.cap<=e.flow||d[e.to]<=d[u]+e.cost)continue;
                d[e.to] = d[u] + e.cost;
                p[e.to] = i;
                a[e.to] = min(a[u],e.cap-e.flow);
                if (!inq[e.to]){Q.push(e.to);inq[e.to]=1;}
            }
        }
        if (d[t]==INF)return 0;//false
        flow += a[t];
        cost += (double)d[t]*(double)a[t];
        //printf("cost=%.2lf\n",cost);
        for (int u=t;u!=s;u=edges[p[u]].from){
            edges[p[u]  ].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        return 1;//true
    }

    //需要保证初始网络中没有负权
    double mcmf(){
        int flow =0;
        double cost = 0;
        for (;spfa(s,t,flow,cost););
        return cost;
    }//MinCostMaxFlow
} g ;

struct point{
    int x,y,d;//d:Degree
    point(){}
    inline void read(){scanf("%d%d",&x,&y);d=0;}
}po[N];
vector <int > link[N];
inline double sqr(double x){return x*x; }
inline double dist(int a,int b){
    return sqrt(sqr(po[a].x-po[b].x)+ sqr(po[a].y-po[b].y));
}

int main(){
    freopen("in.txt","r",stdin);
    int n,dx,dy,x;
    for (int cas=0;~scanf("%d",&n)&&n;){
        scanf("%d%d",&dx,&dy);
        g.Init(n+1,0,n+1);
        for (int i=1;i<=n;i++)link[i].clear();
        for (int i=1;i<=n;i++){
            po[i].read();
            for (;~scanf("%d",&x)&&x;)link[i].push_back(x);
        }
        double ans = 0;
        for (int i=1;i<=n;i++){
            for (int j=0;j<link[i].size();j++){
                double d = dist(i,link[i][j]);
                double cost = (double)dy - 1.0*d * dx ;
                //
                if (cost>0) g.AddEdge(i,link[i][j],1,cost);
                else {
                    ans -= cost;
                    g.AddEdge(link[i][j],i,1,-cost);
                    po[link[i][j]].d++;
                    po[i].d--;
                }
            }
        }
        for (int i=1;i<=n;i++){
            if (po[i].d>0) g.AddEdge(g.s, i, po[i].d, 0);
            if (po[i].d<0) g.AddEdge(i, g.t,-po[i].d, 0);
        }
        ans -= g.mcmf()-EPS;
        printf("Case %d: %.2lf\n",++cas,ans);
    }
    return 0;
}
