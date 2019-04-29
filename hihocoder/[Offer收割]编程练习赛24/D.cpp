#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int N;
int Find(int x) {
    if(x > N) return 0;
    return 1 + Find(x + a[x]);
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) {
        scanf("%d", a + i);
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int x;
        scanf("%d", &x);
        if(x == 1) {
            int y;
            scanf("%d", &y);
            printf("%d\n", Find(y));
        } else {
            int u, v;
            scanf("%d%d", &u, &v);
            a[u] = v;
        }
    }
    return 0;
}
