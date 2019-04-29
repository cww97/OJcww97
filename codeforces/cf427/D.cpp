#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e3 + 10;

int f[N][N], ans[N];
string st;

int main(){
    //freopen("in.txt", "r", stdin);
    for (; cin >> st;){
        memset(f, 0, sizeof(f));
        memset(ans, 0, sizeof(ans));
        //cout << st << endl;
        int n = st.length();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i - j < 0 || i + j >= n) break;
                if (st[i-j] != st[i+j]) break;
                f[i-j+1][i+j+1] = f[i-j+1][i] + 1;
            }
            for (int j = 0; j < n; j++){
                if (i - j < 0 || i + j + 1 >= n) break;
                if (st[i-j] != st[i+j+1]) break;
                f[i-j+1][i+j+2] = f[i-j+1][i+1] + 1;
                ///printf("f[%d][%d] = %d\n", i-j+1, i+j+2, f[i-j+1][i+j+2]);
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++){
                ans[f[i][j]]++;
            }
        }
        for (int i = n-1; i >= 1; i--){
            ans[i] += ans[i+1];
        }
        for (int i = 1; i < n; i++){
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[n]);
    }
    return 0;
}
