#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=107;
int n,g[N][N];

int prim(){
    int minw[N];//MinWeight
    bool used[N];
    memset(used,0,sizeof(used));
    memset(minw,0x7f,sizeof(minw));
    minw[1]=0;
    int sum=0;
    while (1){
        int v=-1;
        for (int i=1;i<=n;i++){
            if (!used[i]&&(v==-1||minw[i]<minw[v]))v=i;
        }
        if (v==-1)break;
        used[v]=1;
        sum+=minw[v];
        for (int i=0;i<=n;i++){
            minw[i]=min(minw[i],g[v][i]);
        }
    }
    return sum;
}

int main(){
    for (;scanf("%d",&n)==1;){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                scanf("%d",&g[i][j]);
            }
        }
        int x,y,q;
        scanf("%d",&q);
        for (;q--;){
            scanf("%d%d",&x,&y);
            g[x][y]=g[y][x]=0;
        }
        printf("%d\n",prim());
    }
    return 0;
}
