#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,m;
	while (~scanf("%d%d",&n,&m)){
		int ans=0,x,y,t;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				scanf("%d",&t);
				if (abs(t)>abs(ans)){
					ans=t;x=i;y=j;
				}
			}
		}
		printf("%d %d %d\n",x,y,ans);
	}
	return 0;
} 
