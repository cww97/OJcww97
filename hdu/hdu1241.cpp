#include <bits/stdc++.h>
using namespace std;
const int N = 111;
const int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[] = {-1,  0 , 1, -1, 1, -1, 0, 1};

char st[N];
int n, m;
int g[N][N];
bool vis[N][N];

void dfs(int x, int y){
    vis[x][y] = true;
    for (int i = 0; i < 8; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cx > n || cy < 1 || cy > m || vis[cx][cy] || (!g[cx][cy])) continue;
        dfs(cx, cy);
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    for (;~scanf("%d%d", &n, &m);){
        if (n == 0) break;
        for (int i = 1; i <= n; i++){
            scanf("%s", st);
            for (int j = 0; j < m; j++){
                g[i][j+1] = st[j]=='@' ? 1 : 0;
            }
        }

        int ans = 0;
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if ((!vis[i][j]) && g[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}