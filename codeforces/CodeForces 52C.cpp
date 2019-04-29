#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 6e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct segmentTree{
    LL tree[N];
    int M, n;

    void build(int n){
        this->n = n;
        M = 1;while (M < n) M <<= 1;if (M!=1) M--;
        for (int t = 1 ; t <= n; t++) scanf("%I64d", &tree[t+M]);
        for (int t = n+1; t <= M+1; t++) tree[t+M] = INF;
        for (int t = M; t >= 1; t--) tree[t] = min(tree[t<<1], tree[t<<1^1]);
        for (int t = 2*M+1; t >= 1; t--) tree[t] = tree[t] - tree[t>>1];
    }

    void update(int l, int r, LL val){
        LL tmp;
        for (l+=M-1, r+=M+1; l^r^1; l>>=1, r>>=1){
            if (~l&1) tree[l^1] += val;
            if ( r&1) tree[r^1] += val;
            if (l > 1) tmp = min(tree[l], tree[l^1]), tree[l]-=tmp, tree[l^1]-=tmp, tree[l>>1]+=tmp;
            if (r > 1) tmp = min(tree[r], tree[r^1]), tree[r]-=tmp, tree[r^1]-=tmp, tree[r>>1]+=tmp;
        }

        for (; l > 1; l >>= 1){
            tmp = min(tree[l], tree[l^1]), tree[l]-=tmp, tree[l^1]-=tmp, tree[l>>1]+=tmp;
        }
        tree[1] += tree[0], tree[0] = 0;
    }

    LL query(int l, int r){
        LL lAns = 0, rAns = 0;
        l += M, r += M;
        if (l != r){
            for (; l^r^1; l>>=1, r>>=1){
                lAns += tree[l], rAns += tree[r];
                if (~l&1) lAns = min(lAns, tree[l^1]);
                if ( r&1) rAns = min(rAns, tree[r^1]);
            }
        }
        LL ans = min(lAns + tree[l], rAns + tree[r]);
        for (;l > 1;) ans += tree[l>>=1];
        return ans;
    }
} T;

int main(){
    ///freopen("in.txt", "r", stdin);
    int n, m, l, r;
    for (LL x; ~scanf("%d", &n);){
        if (n == -1){

        }else{
        }
        T.build(n);
        scanf("%d", &m);
        for (; m--;){
            scanf("%d%d", &l, &r);
            l++, r++;
            char ch = getchar();
            if (ch == ' ') {
                scanf("%I64d", &x);
                if (l <= r) T.update(l, r, x);
                else T.update(1, r, x), T.update(l, n, x);
            }else{
                if (l <= r) printf("%I64d\n", T.query(l, r));
                else printf("%I64d\n", min(T.query(1, r), T.query(l, n)));
            }
        }
    }
    return 0;
}
