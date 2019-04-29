#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1111;
const int M = 22222;
const int INF = 0x3f3f3f3f;

struct SPFA{
    struct Edge{
        int from, to, cost, nxt;
        Edge(){}
        Edge(int x, int y, int z, int w):from(x), to(y), cost(z), nxt(w){}
    } edges[M];
    int n, head[N], E;

    inline void init(int _n){
        n = _n; E = 0;
        for (int i = 0; i <= n; i++) head[i] = -1;
    }

    inline void addEdge(int f, int t, int c){
        edges[E] = Edge(f, t, c, head[f]);
        head[f] = E++;
    }

    bool inq[N];
    int dist[N];
    inline int spfa(const int &s, const int &t){
        queue <int> Q;
        memset(inq, 0, sizeof(inq));
        memset(dist, INF, sizeof(dist));
        dist[s]=0; inq[s]=1;
        for (Q.push(s); !Q.empty();){
            int u = Q.front(); Q.pop(); inq[u]= 0;
            for (int i = head[u]; ~i; i = edges[i].nxt){
                Edge &e = edges[i];
                if (dist[u] + e.cost < dist[e.to]){
                    dist[e.to] = dist[u] + e.cost;
                    if (!inq[e.to]){
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        return dist[t];
    }
} g;


int main(){
    //freopen("in.txt", "r", stdin);
    for(int n, m; ~scanf("%d%d", &n, &m) && n && m;){  
        g.init(n);
        for(int a, b, c; m--;){  
            scanf("%d%d%d", &a, &b, &c);  
            g.addEdge(a, b, c);
            g.addEdge(b, a, c);
        }  
        int ans = g.spfa(1, n);
        printf("%d\n", ans);  
    }  
    return 0;  
}  