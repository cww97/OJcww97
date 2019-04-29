#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int dx[]={0,1,-1,0,0};
const int dy[]={0,0,0,-1,1};
int i,j,n,m,ans,xx,yy,g[1000][1000];

int fuck(int x,int y){
  int haha=0;
  for (int k=1;k<=4;k++)
    if (g[x][y]*g[x+dx[k]][y+dy[k]]<0)
      haha+=abs(g[x+dx[k]][y+dy[k]]);
      else haha-=abs(g[x+dx[k]][y+dy[k]]);
  return haha;
}

int main(){
  while(cin>>n>>m&&n&&m){
    memset(g,0,sizeof(g));

    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++) cin>>g[i][j];
    ans=-999999;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++){
        int t=fuck(i,j);
        if (t>ans){ans=t;xx=i;yy=j;}
    }
    cout<<xx<<" "<<yy<<" "<<ans<<endl;
  }
  return 0;
}
