#include<cstdio>
#include<iostream>
using namespace std;
int n,x,m,ti,fin[11],ok[55000];

int main(){
///freopen("fuck.in","r",stdin);
	while(scanf("%d%d",&n,&m)==2){
		for (int i=1;i<=n;i++){
			ti=0;
			for (int j=1;j<=m;j++){
				scanf("%d",&x);
				ti=max(ti,fin[j])+x;
				fin[j]=ti;
			}
			ok[i]=ti;
		}
		for (int i=1;i<n;i++)printf("%d ",ok[i]);
		printf("%d",ok[n]);
	} 
	return 0;
} 
