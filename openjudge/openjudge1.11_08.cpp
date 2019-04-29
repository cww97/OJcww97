#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int arr[N], n;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", &arr[i]);

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)if (arr[i] != arr[i+1]){
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}
