#include <bits/stdc++.h>
using namespace std;
const int N = 7;
const int dx[] = {-1, 1,  0, 0};
const int dy[] = { 0, 0, -1, 1};

int n, m, fx, fy, g[N][N], ans;
bool vis[N][N];
int pathx[N*N], pathy[N*N];

void printPath(){
    for (int i = 1; i <= dep; i++){
        printf("(%d, %d)->", pathx[i], pathy[i]);
    }
}

void dfs(int x, int y, int dep){ // depth
    //printf("dfs(%d, %d)\n", x, y);
    pathx[dep] = x;
    pathy[dep] = y;
    if (x == fx && y == fy){
        ans++;
        printPath(dep);
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
        if (vis[cx][cy] || g[cx][cy] == 1) continue;
        dfs(cx, cy, dep+1);
    }
    vis[x][y] = false;
}

int main(){
    freopen("in.txt", "r", stdin);
    int t, sx, sy;
    scanf("%d%d%d%d%d%d%d", &n, &m, &t, &sx, &sy, &fx, &fy);
    memset(g, 0, sizeof g);
    for (int x, y; t--;){
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }
    ans = 0;
    memset(vis, 0, sizeof vis);
    dfs(sx, sy, 1);
    printf("%d\n", ans);
    return 0;
}
