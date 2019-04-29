#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 999;
int a[N];
int n;
bool cmp(int x,int y){
    return abs(x) < abs(y);
}

int main(){
    for (;~scanf("%d", &n);){
        for (int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a + n, cmp);
        for (int i=0; i<n-1; i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);
    }
    return 0;
}
