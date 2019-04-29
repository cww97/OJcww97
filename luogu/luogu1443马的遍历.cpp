#include <bits/stdc++.h>
using namespace std;
const int N = 444;
const int dx[] = {-2, -2, -1, -1,  1, 1,  2, 2};
const int dy[] = {-1,  1, -2,  2, -2, 2, -1, 1};

int n, m, ans[N][N];

struct Node{
    int x, y;
    Node(int _x, int _y):x(_x), y(_y){}

    void print(){
        printf("Node: (%d, %d)\n", x, y);
    }
};

void bfs(int sx, int sy){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ans[i][j] = -1;
        }
    }
    ans[sx][sy] = 0;
    queue <Node> Q;
    Q.push(Node(sx, sy));
    while (!Q.empty()){
        Node cur = Q.front(); Q.pop(); // current == now
        // cur.print(); printf("step = %d\n", ans[cur.x][cur.y]);
        for (int i = 0; i < 8; i++){
            int cx = cur.x + dx[i];
            int cy = cur.y + dy[i];
            if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
            if (ans[cx][cy] != -1) continue;
            ans[cx][cy] = ans[cur.x][cur.y] + 1;
            Q.push(Node(cx, cy));
        }
    }
}

int main(){
    //freopen("out.txt", "w", stdout);
    int sx, sy;
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    bfs(sx, sy);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            printf("%-5d", ans[i][j]);  // answer
        }
        printf("\n");
    }
    return 0;
}
