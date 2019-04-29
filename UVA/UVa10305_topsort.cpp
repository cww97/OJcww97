#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn=107;
int x,y,m,n;
bool f[maxn][maxn];
int in[maxn];

int main(){
	//freopen("fuck.in" ,"r",stdin);
    while(scanf("%d%d",&n,&m)==2&&(m||n)){
        memset(f ,0,sizeof(f ));
        memset(in,0,sizeof(in));
        for(;m--;){
            scanf("%d%d",&x,&y);
            f[x][y] = 1;
            in[y]++;
        }

        int A=0,ans[maxn];
        queue<int>Q;
        for (int i=1;i<=n;i++)if (in[i]==0)Q.push(i);
        while(!Q.empty()){
            int x=Q.front(); Q.pop();
            ans[++A]=x;
            for(int j=1;j<=n;j++)if (f[x][j]){
                if (--in[j]==0)Q.push(j);
            }
        }
        for (int i=1;i<A;i++)printf("%d ",ans[i]);
        printf("%d\n",ans[A]);
    }
    return 0;
}
