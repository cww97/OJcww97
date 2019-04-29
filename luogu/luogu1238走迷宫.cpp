#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int N = 22;
const int dx[] = { 0,-1, 0, 1}; // direction
const int dy[] = {-1, 0, 1, 0};

int n, m, g[N][N], ex, ey;
bool vis[N][N], ok; // visited
vector <P> ans;

void printAns(){
    for (int i = 0; i < ans.size()-1; i++){
        printf("(%d,%d)->", ans[i].first, ans[i].second);
    }
    printf("(%d,%d)\n", ex, ey);
}

void dfs(int x, int y){
    //printf("dfs(%d, %d)\n", x, y);
    vis[x][y] = true;
    ans.push_back(P(x, y));
    if (x==ex && y==ey){
        ok=true;
        printAns();
        vis[x][y] = false;
        ans.pop_back();
        return;
    }

    for (int i = 0; i < 4; i++){
        int cx = x + dx[i]; // cur, current
        int cy = y + dy[i];
        if (cx<1 || cx > n || cy<1 || cy>m) continue;
        if (vis[cx][cy] || g[cx][cy] == 0) continue;

        dfs(cx, cy);

    }
    vis[x][y] = false;
    ans.pop_back();
    //printf("End==dfs(%d, %d)\n", x, y);
}

int main(){
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    int sx, sy;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    memset(vis, 0, sizeof vis);
    ans.clear();
    ok = false;
    dfs(sx, sy);
    if (!ok) puts("-1");
    return 0;
}
