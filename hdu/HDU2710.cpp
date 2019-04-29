#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
const int N=200000;
int prime[N+100],len,n,Max=0;
int ans=1;
bool v[N+100];
void get_prime(){
    for (int i=2;i<N;i++){
        if (!v[i]) prime[++len]=i;
        for (int j=1;j<=len&&i*prime[j]<N;j++){
            v[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}
void Do(int x){
    if (x==1){
        if (Max<1) Max=1,ans=x;
        return;
    }
    for (int i=1;i<=len&&prime[i]<=x;i++){
        if (x%prime[i]==0){
            if (prime[i]>Max) Max=prime[i],ans=x;
        }
    }
}
int main(){
    get_prime();
    for (;~scanf("%d",&n);){
            Max=0; ans=0;
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        Do(x);
    }
    printf("%d\n",ans);
    }
    return 0;
}
