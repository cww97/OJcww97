#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 7;

int x[N], n;

int Find(int num){
    int l = 0, r = n - 1;
    for (; l < r;){
        int mid = (l + r) / 2;
        if (x[mid] == num) return mid;
        if (x[mid] < num) l = mid + 1;
        else r = mid;
    }
    if (x[l] == num) return l;
    return -1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int c;
    scanf("%d", &c);

    sort(x, x + n);

    for (int i = 0; i < n; i++) {
        int idx = Find(c - x[i]);
        if (idx != -1) {
            if (idx == i && (x[i-1] == x[i] || x[i] == x[i+1])){
                printf("%d %d\n", x[i], x[i]);
                return 0;
            }else if (idx != i){
                printf("%d %d\n", x[i], c-x[i]);
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}
