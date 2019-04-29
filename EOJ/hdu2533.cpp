#include <bits/stdc++.h>
using namespace std;
const int N = 33;

int ans, n, queen[N];
bool col[N], diag1[N], diag2[N];

bool canPutQueen(const int &x, const int &y){
    if (col[y]) return false;
    if (diag1[x+y]) return false;
    if (diag2[n+x-y]) return false;
    return true;
}

inline void putQueen(const int &x, const int &y){
    queen[x] = y;
    col[y] = true;
    diag1[x+y] = true;
    diag2[n+x-y] = true;
}

inline void removeQueen(const int &x, const int &y){
    queen[x] = 0;
    col[y] = false;
    diag1[x+y] = false;
    diag2[n+x-y] = false;
}

void dfs(int k){
    if (k == n+1) {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (canPutQueen(k, i)){
            putQueen(k, i);
            dfs(k+1);
            removeQueen(k, i);
        }
    }
}

int f[N];

int F(const int &n){
    if (f[n]) return f[n];
    ans = 0;
    memset(col, 0, sizeof col);
    memset(diag1, 0, sizeof diag1);
    memset(diag2, 0, sizeof diag2);
    dfs(1);
    return f[n] = ans;
}

int main(){
    int _;
    //cin >> _;
    for (; ~scanf("%d", &n) && n;){
        printf("%d\n", F(n));
    }
    return  0;
}
