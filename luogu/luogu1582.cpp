#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (;__builtin_popcount(n) > k;){
        ans += lowbit(n);
        n += lowbit(n);
    }
    cout << ans << endl;
    return 0;
}