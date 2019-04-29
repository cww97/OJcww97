#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
char st[N];
int arr[N];

int main(){
    //freopen("in.txt", "r", stdin);
    int k;
    for (;~scanf("%d", &k);){
        scanf("%s", st);
        int n = strlen(st);
        int sum = 0;
        for (int i = 0; i < n; i++){
            arr[i] = st[i] - '0';
            sum += arr[i];
        }
        if (sum >= k) puts("0");
        else{
            sort(arr, arr + n);
            int ans = 0;
            for (int i = 0; i < n && sum < k; i++){
                sum += 9 - arr[i];
                ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
