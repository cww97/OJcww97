#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e5 + 7;
int l[N], r[N];

struct binaryIndexTree{
    int tree[N], n;
    inline void init(int n){
        this->n = n;
        memset(tree, 0, sizeof(tree));
    }
    inline void add(int k, int num){
        for (;k <= n; k += k&-k) tree[k] += num;
    }
    int sum(int k){
        int sum = 0;
        for (; k; k -= k&-k) sum += tree[k];
        return sum;
    }
} T;

struct graph{
    struct Edge{
        int from, to, nxt;
        Edge(){}
        Edge(int u, int v, int n):from(u), to(v), nxt(n){}
    }edges[N];
    int n, E, head[N];
    int top;

    inline void AddEdge(int f, int t){
        edges[++E] = Edge(f, t, head[f]);
        head[f] = E;
    }
    inline void Init(int n){
        this -> n = n ; E = -1; top = 0;
        for (int i = 0; i <= n; i++) head[i] = -1;
    }
    void dfs(int u){
        l[u] = ++top; T.add(top, 1);
        for (int i = head[u]; i != -1; i = edges[i].nxt){
            dfs(edges[i].to);
        }
        r[u] = ++top; T.add(top, -1);
    }
} g ;

int main(){
    //freopen("in.txt", "r", stdin);
    int n, m, u, v;
    char ch;
    for (; ~scanf("%d", &n);){
        g.Init(n);
        T.init(n*2);
        for (int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            if (u > v) swap(u, v);
            g.AddEdge(u, v);
        }
        g.dfs(1);

        scanf("%d", &m);
        for (m += n-1; m--;){
            getchar();
            scanf("%c %d", &ch, &u);
            if (ch == 'W') printf("%d\n", T.sum(l[u])-1);
            else {
                scanf("%d", &v);
                if (u > v) swap(u, v);
                T.add(l[v], -1); T.add(r[v], 1);
            }
        }
    }
    return 0;
}
