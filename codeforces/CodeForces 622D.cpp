#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100086;
int a[N],n;
int main(){
    for (;~scanf("%d",&n);){
        memset(a,0,sizeof(a));
        if (n%2==0){
            for (int i=1;i<=n;i+=2) printf("%d ",i);
            for (int i=n-1;i>=1;i-=2) printf("%d ",i);
            for (int i=2;i<=n;i+=2) printf("%d ",i);
            for (int i=n-2;i>=2;i-=2) printf("%d ",i);
            printf("%d\n",n);
        }else{
            for (int i=1;i<=n;i+=2) printf("%d ",i);
            for (int i=n-2;i>=1;i-=2) printf("%d ",i);
            for (int i=2;i<=n;i+=2) printf("%d ",i);
            for (int i=n-1;i>=2;i-=2) printf("%d ",i);
            printf("%d\n",n);
        }
    }
    return 0;
}
