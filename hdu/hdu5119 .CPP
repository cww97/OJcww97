#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=1100000,M=1<<20;
int i,a[44],n,m,f[44][N];

int main(){
    //freopen("fuck.in","r",stdin);
    int T;scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        scanf("%d%d",&n,&m);
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)scanf("%d",&a[i]);
        f[0][0]=1;
        for (int i=1;i<=n;i++)
          for (int j=0;j<=M;j++)
              f[i][j]=f[i-1][j]+f[i-1][j^a[i]];
        LL ans=0;
        for (int i=m;i<=M;i++)ans+=f[n][i];
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
} 
