#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 7;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n;
int arr[N];
LL sum[N];

int check(int idx){
    LL ssum = 0;
    for (int i = idx + 1; i <= n; i++){
        ssum += arr[i];
        if (ssum <= 0) return -1;
    }
    for (int i = 1; i <= idx; i++){
        ssum += arr[i];
        if (ssum <= 0) return -1;
    }
    return idx<n ? idx+1 : 1;
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    LL Min = INF;
    int idx = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        sum[i] = sum[i-1] + arr[i];
        if (Min >= sum[i]){
            Min = sum[i];
            idx = i;
        }
    }
    printf("%d\n", check(idx));
    return 0;
}
