#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1000086;
int a[N],b[N],f[N];
int n,m;
bool flag=0;
void Find(int *T,int *P){
    int j=0;
    for (int i=0;i<n;i++){
        for (;j&&P[j]!=T[i];) j=f[j];
        if (P[j]==T[i]) j++;
        if (j==m){
            printf("%d\n",i-m+2),flag=1;
            return;
        }
    }
}
void GetFail(int *P){
    f[0]=f[1]=0;
    for (int i=1;i<m;i++){
        int j=f[i];
        for (;j&&P[i]!=P[j];) j=f[j];
        f[i+1]=P[i]==P[j]?j+1:0;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for (;T--;){
        scanf("%d%d",&n,&m);
        flag= 0;
        memset(f,0,sizeof(f));
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<m;i++) scanf("%d",&b[i]);
        GetFail(b);
      //  puts("!!!!");
        Find(a,b);
     //   puts("!!!!");
        if (!flag) puts("-1");
    }
    return 0;
}
