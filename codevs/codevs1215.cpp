#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int i,j,g[20][20],sx,sy,ex,ey,n;
bool vis[20][20];
char ch;

bool dfs(int x,int y){
	if (x==ex&&y==ey)return 1;
	//printf("x=%d y=%d\n",x,y);
	for (int i=0;i<4;i++){
		int cx=x+dx[i];
		int cy=y+dy[i];
		if (g[cx][cy]||vis[cx][cy])continue;
		vis[cx][cy]=1;
		if (dfs(cx,cy))return 1;
	}
	return 0;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;cin>>T;
	for (;T--;){
		cin>>n;
		memset(g,1,sizeof(g));
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				cin>>ch;
				if (ch=='#')g[i][j]=1;
				else g[i][j]=0;
				if (ch=='s'){sx=i;sy=j;}
				if (ch=='e'){ex=i;ey=j;}
		    }
		}
		
		vis[sx][sy]=1;
		if (dfs(sx,sy))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
