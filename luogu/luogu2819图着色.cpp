#include <bits/stdc++.h>
using namespace std;
const int N = 111;

int n, k, m, col[N], cnt;
vector <int> G[N];

bool canColor(int u, int c){ // col
    for (int i = 0; i < G[u].size(); i++){
        if (c == col[G[u][i]]) return false;
    }
    return true;
}

void dfs(int dep){
    //printf("dfs(%d)\n", dep);
    if (dep == n+1){
        cnt++;
        return;
    }

    for (int i = 1; i <= k; i++) {
        //printf("\t?? %d\n", )
        if (!canColor(dep, i)) continue;
        col[dep] = i;
        dfs(dep+1);
        col[dep] = 0;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int x, y; m--;){
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cnt = 0;
    memset(col, 0, sizeof col);
    dfs(1);
    printf("%d\n", cnt);
    return 0;
}
