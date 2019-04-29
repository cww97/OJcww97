#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int Getc[MAXN];
int Sum[MAXN];
int main(){
    //freopen("in.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        scanf("%d", Getc + i);
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(Getc[i] == 0) {
            a[cnt++] = i;
        }
    }
    for(int i = 0; i < cnt; i++) {
        a[cnt + i] = a[i] + N;
    }
    Sum[0] = a[0];
    for(int i = 1; i < cnt * 2; i++) {
        Sum[i] = Sum[i - 1] + a[i];
    }
    if(cnt < M) {
        printf("-1\n");
        return 0;
    }
    int ans = a[M / 2] * (M / 2) - Sum[M / 2 - 1] + Sum[M - 1] - Sum[M / 2] - (M - 1 - M / 2) * a[M / 2];
    for(int i = 1; i < cnt; i++) {
        ans = min(ans, a[(i + i + M) / 2] * (M / 2) - Sum[(i + i + M) / 2 - 1] + Sum[i - 1] + Sum[M + i - 1] - Sum[(i + i + M) / 2] - (M - 1 - M / 2) * a[(i + i + M) / 2]);
    }
    printf("%d\n", ans);
    return 0;
}
