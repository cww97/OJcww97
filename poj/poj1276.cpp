#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100007;
struct node {
    int v,w,n;
    node(){}
    node(int x,int y,int z){
        v=x,w=y,n=z;
    }
}a[N];
int f[N];

int va[N], vb[N];//MAX_V
void pack(int V,int v,int w,int n){
    if (n==0||v==0) return;
    if (n==1){//01背包
        for (int i=V;i>=v;--i)
            f[i]=max(f[i],f[i-v]+w);
        return;
    }
    if (n*v>=V-v+1){//完全背包(n >= V / v)
        for (int i=v;i<=V;++i)
            f[i]=max(f[i],f[i-v]+w);
        return;
    }
    for (int j = 0 ; j < v ; ++j ){
        int *pb = va, *pe = va - 1;
        int *qb = vb, *qe = vb - 1;
        for (int k=j,i=0;k<=V;k+=v,++i){
            if (pe==pb+n){
                if(*pb == *qb) ++qb;
                ++pb;
            }
            int tt = f[k] - i * w;
            *++pe = tt;
            while (qe>=qb&& *qe<tt)--qe;
            *++qe = tt;
            f[k] = *qb + i * w;
        }
    }
}

int main(){
    //freopen("fuck.in","r",stdin);
    int cash,n,x,y;
    for (;~scanf("%d%d",&cash,&n);){
        for(int i=1;i<=n;i++){    //init
            scanf("%d%d", &x, &y);
            a[i] = node(y,y,x) ;
        }
        memset(f,0,sizeof(f));    //pack
        for (int i=1;i<=n;i++)
            pack(cash,a[i].v,a[i].w,a[i].n);
        int ans = 0;              //getAns
        for (int i=0;i<=cash;i++) ans=max(ans,f[i]);
        printf("%d\n",ans);
    }
    return 0;
}
