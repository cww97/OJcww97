#include<cstdio>
using namespace std;
int i,m,n,f[30][30];
int main(){
  scanf("%d%d",&n,&m);
  f[1][0]=1;
  for (int j=1;j<=m;j++){
    f[0][j-1]=f[n][j-1];
    f[n+1][j-1]=f[1][j-1];
    for (int i=1;i<=n;i++)
      f[i][j]=f[i-1][j-1]+f[i+1][j-1];
  }
  printf("%d\n",f[1][m]);
  return 0;
}
