#include<cstdio>
#include<cstring>
using namespace std;
const int dx[9]={0,-1,-1,-1,0,0,1,1,1};
const int dy[9]={0,-1,0,1,-1,1,-1,0,1};
int m,n,i,j,g[110][110],ans=0;
char ch;

void dfs(int x,int y)
{
	g[x][y]=1;
	for (int i=1;i<=8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if (g[nx][ny]==0)dfs(nx,ny);
	}
}

int main ()
{
	scanf("%d%d",&n,&m);
	for (i=0;i<=n+1;i++)
	    for (j=0;j<=m+1;j++)g[i][j]=1;
	for (i=1;i<=n;i++)
	{
		scanf("%c",&ch);
	    for (j=1;j<=m;j++)
	    {
	    	scanf("%c",&ch);
	    	if (ch=='.')g[i][j]=1;
	    	else g[i][j]=0;
	    }
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
		if (g[i][j]==0){dfs(i,j);ans++;}
	printf("%d\n",ans);
	return 0;
} 
