#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e6 + 7;
const int M = 100000073;
const int INF = 0x3f3f3f3f;
int f[N], g[N], sumG[N];

int main()
{
    /*
    memset(f, INF, sizeof(f));
    f[0] = 0;
    f[1] = g[1] = g[0] = 1;
    for (int i = 2; i < 44; i++){
        for (int j = 1; j <= i; j++){
            f[i] = min(f[i], 1 + max(j-1, f[i-j]));
        }
        printf("f[%d] = %d : ", i, f[i]);
        for (int j = 1; j <= i; j++){
            if (f[i] == 1 + max(j-1, f[i-j])){
                g[i] = (g[i] + g[j]) % M;
                printf("%d ", i-j);
            }
        }
        puts("");
    }
    */

    memset(g, 0, sizeof(0));
    memset(f, INF, sizeof(f));
    f[0] = 0;
    f[1] = g[1] = g[0] = sumG[0] = 1;
    sumG[1] = 2;
    int l = 1, r = 2;
    for (int i = 2; i < N; i++){
        f[i] = 1 + max(r-1, f[i-r]);
        /*
        for (int j = i-r; j <= i-l; j++){
            g[i] = (g[i] + g[j]) % M;
        }*/
        g[i] = (sumG[i-l] - sumG[i-r-1] + M) % M;
        sumG[i] = (sumG[i-1] + g[i]) % M;
        l++;
        if (l > r) l = 1, r++;
        //printf("i = %d: f:%d, g:%d\n", i, f[i], g[i]);
    }
    for (int a, b; ~scanf("%d%d", &a, &b);){
        printf("%d %d\n",f[b-a+1], g[b-a+1]);
    }
    return 0;
}
