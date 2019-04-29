#include <cstdio>
#include <iostream>
using namespace std;

int work(int n){
    int ans = n;
    while (n>=3){
        ans += n/3;
        n = (n/3) + (n%3);
    }
    return ans;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int T, n;
    scanf("%d", &T);
    for(;T--;){
        scanf("%d", &n);
        printf("%d\n",work(n));
    }
    return 0;
}
