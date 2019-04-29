#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=100086;
int C[N*4];
int a[N],n;
ll f[N],g[N];
void Add(int x,int d){
    for (;x<=n;x+=x&-x) C[x]+=d;
}
int Query(int x){
    int re=0;
    for (;x;x-=x&-x) re+=C[x];
    return re;
}
int scan(){
    char ch=getchar();
    int x=0;
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch<='9'&&ch>='0';ch=getchar()) x+=(x<<3)+x+ch-48;
    return x;
}
int main(){
    int T=scan();
    for (;T--;){
        n=scan();
        memset(C,0,sizeof(C));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for (int i=1;i<=n;i++){
            a[i]=scan();
            f[i]=Query(a[i]-1);
            Add(a[i],1);
        }
        memset(C,0,sizeof(C));
        for (int i=n;i;i--){
            g[i]=g[i+1]+Query(n)-Query(a[i]);
            Add(a[i],1);
        }
        ll ans=0;
        //for (int i=1;i<=n;i++) printf("f[%d]=%I64d  g[%d]=%I64d\n",i,f[i],i,g[i]);
        for (int i=1;i<n;i++) ans+=f[i]*g[i+1];
        cout<<ans<<endl;
    }
    return 0;
}
