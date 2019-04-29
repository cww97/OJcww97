#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

int main() {
    int x, n;
    LL cnt = 0;
    scanf("%d %d", &x, &n);
    x %= 7;
    for (int i = 1; i <= n; i++) {
        if (x != 6 && x != 0) {
            cnt += 250;
        }
        x = (x+1) % 7;
    }
    cout << cnt << endl;
    return 0;
}
