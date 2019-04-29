/*
作者:CWW970329
题目:p1160 蛇形矩阵
*/ 
#include<cstdio>
int i,j,k,num=1,x,y,n,sum=-1,g[110][110];
int main(){
	scanf("%d",&n);
	g[x=n/2+1][y=n/2+1]=1;
    for (k=1;k<=n/2;k++){
        x++;  y++;
        for (i=1;i<=k*2;i++) g[--x][y]=++num;
        for (i=1;i<=k*2;i++) g[x][--y]=++num;
        for (i=1;i<=k*2;i++) g[++x][y]=++num;
        for (i=1;i<=k*2;i++) g[x][++y]=++num;
    }
    for (i=1;i<=n;i++){
    	for (j=1;j<n;j++)printf("%d ",g[i][j]);
    	printf("%d\n",g[i][n]);
    }
    for (i=1;i<=n;i++) sum+=g[i][i]+g[i][n-i+1];
    printf("%d\n",sum);
    return 0;
}
