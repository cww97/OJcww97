#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
struct P{int x,y,v;}a[1000];
int n,d,i,j,maxy,ans=0,g[200][200];

void work(int x,int y){
  int haha=0;
  for (int i=1;i<=n;i++)
    if (a[i].x>=x-d&&a[i].x<=x+d&&
        a[i].y>=y-d&&a[i].y<=y+d)haha+=a[i].v;
  g[x][y]=haha;
  maxy=max(maxy,haha);
}

int main(){
  cin>>d>>n;
  for (int i=1;i<=n;i++)
     cin>>a[i].x>>a[i].y>>a[i].v;
  maxy=0;
  for (int i=0;i<=128;i++)
    for (int j=0;j<=128;j++) work(i,j);
  for (int i=0;i<=128;i++)
    for (int j=0;j<=128;j++)
      if (g[i][j]==maxy)ans++;
  cout<<ans<<" "<<maxy<<endl;
  return 0;
}
