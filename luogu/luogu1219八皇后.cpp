#include <bits/stdc++.h>
using namespace std;
const int N = 33;

int n, cnt, ans[N];
bool col[N], diag1[N], diag2[N];

void printAns(){
    cnt++;
    if (cnt > 3) return;
    for (int i = 1; i < n; i++){
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[n]);
}

void dfs(int dep){
    if (dep == n+1){
        printAns();
        return;
    }

    for (int i = 1; i <= n; i++){
        if (col[i] | diag1[dep-i+n] | diag2[dep+i]) continue;
        ans[dep] = i;
        col[i] = diag1[dep-i+n] = diag2[dep+i] = true;
        dfs(dep + 1);
        col[i] = diag1[dep-i+n] = diag2[dep+i] = false;
    }
}

int main(){
    scanf("%d", &n);
    cnt = 0;
    memset(col, 0, sizeof col);
    dfs(1);
    printf("%d\n", cnt);
    return 0;
}
