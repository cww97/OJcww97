#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1007;
int n;
double g[N][N],maxw[N][N];
bool used[N][N];
struct City{
    int x,y,w;//w=population
    City():x(0),y(0),w(0){}
    City(int _x,int _y,int _w):x(_x),y(_y),w(_w){}
}citys[N];
double dist(City a,City b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double prim(){
    int from[N];
    bool vis[N];
    double minw[N];
    for(int i=1;i<=n;i++){
        minw[i]=g[1][i];
        from[i]=1;
    }
    memset(used,0,sizeof(used));
    memset(maxw,0,sizeof(maxw));
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    minw[1]=0;
    double sum=0;
    while (1){
        int v=-1;
        for (int i=1;i<=n;i++)if (!vis[i]){
            if (v==-1||minw[i]<minw[v])v=i;
        }
        if (v==-1)break;
        //printf("from[%d]=%d\n",v,from[v]);
        used[v][from[v]]=used[from[v]][v]=1;
        vis[v]=1;
        sum+=minw[v];
        //printf("minw[%d]=%.8lf\n",v,minw[v]);
        for (int i=1;i<=n;i++){
            if (!vis[i]&&g[v][i]<minw[i]){
                minw[i]=g[v][i];
                from[i]=v;
            }
            if (vis[i]&&i!=v){
                maxw[i][v]=maxw[v][i]=max(maxw[i][from[v]],minw[v]);
                //printf("    maxw[%d][%d]=%.8lf\n",i,v,maxw[i][v]);
            }
        }
    }
    //for (int i=1;i<=n;i++)printf("from[%d]=%d\n",i,from[i]);
    return sum;
}

int main(){
    //freopen("fuck.in","r",stdin);
    int T;scanf("%d",&T);
    for (;T--;){
        scanf("%d",&n);int x,y,z;
        for (int i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            citys[i]=City(x,y,z);
        }
        for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)
            g[i][j]=dist(citys[i],citys[j]);

        double sum=prim(),ans=-1;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (used[i][j])ans=max(ans,(citys[i].w+citys[j].w)/(sum-g[i][j]));
                else ans=max(ans,(citys[i].w+citys[j].w)/(sum-maxw[i][j]));
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
