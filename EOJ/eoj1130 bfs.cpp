#include <bits/stdc++.h>
using namespace std;
const int N = 33;

struct Node{
    int queen[N], x;
    bool col[N], diag1[N], diag2[N];

    Node(){
        x = 1;
        memset(col, 0, sizeof col);
        memset(diag1, 0, sizeof diag1);
        memset(diag2, 0, sizeof diag2);
        memset(queen, 0, sizeof queen);
    }

    bool canPutQueen(const int &n, const int &y){
        if (col[y]) return false;
        if (diag1[x+y]) return false;
        if (diag2[n+x-y]) return false;
        return true;
    }

    inline void print(){
        printf("-------(%d, %d)-----\n", x-1, queen[x-1]);
    }
};

inline Node putQueen(const int &n, const Node &now, const int &y){
    Node ans = now;
    int x = now.x;
    ans.queen[x] = y;
    ans.col[y] = true;
    ans.diag1[x+y] = true;
    ans.diag2[n+x-y] = true;
    ans.x++;
    //printf("put queen (%d, %d)\n", x, y);
    return ans;
}

inline int bfs(const int &n){
    Node tmp;
    queue <Node> Q;
    Q.push(tmp);
    int ans = 0;
    for (; !Q.empty();){
        Node now = Q.front(); Q.pop();
        //now.print();
        if (now.x == n+1){
            ans++;
            continue;
        }
        for (int i = 1; i <= n; i++){
            //printf("i = %d\n", i);
            if (now.canPutQueen(n, i)){
                tmp = putQueen(n, now, i);
                Q.push(tmp);
            }
        }
    }
    return ans;
}

int f[N];
int F(const int &n){
    return f[n] ? f[n]: f[n] = bfs(n);
}

int main(){
    //freopen("in.txt", "r", stdin);
    int _;
    cin >> _;
    for (int n; ~scanf("%d", &n);){
        printf("%d\n", F(n));
    }
    return  0;
}
