#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 7;
LL a[N], ans;
int n;
bool NotRoot[N];
int FindRoot(){
    for (int i = 1; i <= n; i++)
        if (!NotRoot[i]) return i;
    return -1;
}

struct Edge{
    int from, to, nxt;
    Edge(){}
    Edge(int u, int v, int n):from(u), to(v), nxt(n){}
} edges[N * 2];
int E, head[N];
LL dist[N];
inline void AddEdge(int f, int t){
    edges[++E] = Edge(f, t, head[f]);
    head[f] = E;
}
inline void Init(){
    E = -1;
    for (int i = 0; i <= n; i++) head[i] = -1;
    for (int i = 0; i <= n; i++) dist[i] = 0;
}

int dfs(int u, int pre){
    //printf("dfs(%d, %d)\n", u, pre);
    LL Max = 0;
    for (int i = head[u]; i != -1; i = edges[i].nxt){
        Edge &e = edges[i];
        dfs(e.to, u);
        Max = max(Max, dist[e.to]);
    }
    dist[u] = Max + a[u];
    for (int i = head[u]; i != -1; i = edges[i].nxt){
        Edge &e = edges[i];
        ans += Max - dist[e.to];
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    int u, v;
    for (; ~scanf("%d", &n);){
        a[0] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        Init();
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            AddEdge(u, v);
            NotRoot[v] = 1;
        }
        int root = FindRoot();
        ans = 0;
        dfs(root, -1);
        printf("%lld\n", ans);
    }
    return 0;
}
