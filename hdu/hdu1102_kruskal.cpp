#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=107;
int n,m,g[N][N];
struct Edge{
    int x,y,w;
    Edge():x(0),y(0),w(0){}
    Edge(int _x,int _y,int _w):x(_x),y(_y),w(_w){}
    bool operator < (const Edge &a)const{return w<a.w;}
}edges[N*N];
int home[N];//²¢²é¼¯
int Find(int x){return home[x]==x?x:home[x]=Find(home[x]);}

int kruskal(){
    sort(edges+1,edges+m+1);
    for (int i=1;i<=n;i++)home[i]=i;
    int sum=0,cnt=0;
    for (int i=1;i<=m;i++){
        int x=Find(edges[i].x);
        int y=Find(edges[i].y);
        if (x==y)continue;
        home[x]=y;
        sum+=edges[i].w;
        cnt++;
        if (cnt==n-1)break;
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
        m=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<i;j++){
                edges[++m]=Edge(i,j,g[i][j]);
            }
        }
        printf("%d\n",kruskal());
    }
    return 0;
}
