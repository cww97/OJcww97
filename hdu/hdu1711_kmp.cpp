//hdu1711 cww97
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1000007;
int Next[N],n,m,a[N],b[N];

void GetNext(int m){
    int i=0,j=-1;
    Next[0]=-1;
    while (i<m){
        if (j==-1||b[i]==b[j]){
            if (b[++i]!=b[++j])Next[i]=j;
            else Next[i]=Next[j];
        }else j=Next[j];
    }
}

int kmp(int n,int m){
    int i=0,j=0;
    GetNext(m);
    while (i<n&&j<m){
        if (j==-1||a[i]==b[j])i++,j++;
        else j=Next[j];
        if (!i&&!j)break;
    }
    if (j==m)return i-m+1;
    else return -1;
}

int main(){
    //freopen("fuck.in","r",stdin);
    int T;scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i=0;i<n;i++)scanf("%d",&a[i]);
        for (int i=0;i<m;i++)scanf("%d",&b[i]);
        if (n<m)puts("-1");
        else printf("%d\n",kmp(n,m));
    }
    return 0;
}
