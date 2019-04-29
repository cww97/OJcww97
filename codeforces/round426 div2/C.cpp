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

int main(){
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    LL a, b;
    for (;n--;){
        scanf("%I64d%I64d", &a, &b);
        LL k = (int)(pow(a*b, 1.0/3) + EPS);
        //printf("k = %lld\n", k);
        if (a % k == 0 && b % k == 0) puts("Yes");
        else puts("No");
    }
    return 0;
}
