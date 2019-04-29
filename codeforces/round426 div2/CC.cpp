#include <map>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e6 + 7;
const int MAX = 0x3f3f3f3f;
const double EPS = 1e-8;

LL ssqrt(LL x){
    LL l = 1, r = (LL)(pow(x,1.0/3) + 10);
    for (;l < r;){
        LL m = (l + r) >> 1;
        //printf("mid = %I64d\n", m);
        LL mm = m*m*m;
        if (mm == x) return m;
        else if (mm < x) l = m + 1;
        else r = m;
    }
    return -1;
}

LL sssqrt(LL x){
    LL tmp = pow(1.0 * x, 1.0 / 3);
    for (LL i = tmp-5; i <= tmp + 5; i++){
        if (i*i*i == x) return i;
    }
    return -1;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    LL a, b;
    for (;n--;){
        scanf("%I64d%I64d", &a, &b);
        LL k = ssqrt(a * b);
        //printf("k = %I64d\n", k);
        if (k > -1 && a % k == 0 && b % k == 0) puts("Yes");
        else puts("No");
    }
    return 0;
}
