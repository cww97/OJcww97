#include <map>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 7;
const int MAX = 0x3f3f3f3f;
char st[N];
int arr[N], Min[33], Max[33];

int main(){
    //freopen("in.txt", "r", stdin);
    char chA, chB;
    int n, k;
    for (;~scanf("%d%d", &n, &k);){
        scanf("%s", st);
        memset(Min, MAX, sizeof(Min));
        memset(Max,  0 , sizeof(Max));
        for (int i = 0; st[i] != '\0'; i++){
            int in = st[i] - 'A';
            Min[in] = min(Min[in], i);
            Max[in] = max(Max[in], i);
        }
        int ans = 0;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < 26; i++){
            for (int j = Min[i]; j <= Max[i]; j++){
                arr[j]++;
                ans = max(ans, arr[j]);
            }
        }
        if (ans <= k) puts("NO");
        else puts("YES");
    }
    return 0;
}
