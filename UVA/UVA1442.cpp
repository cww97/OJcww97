#include<cstdio>
#include<iostream>
using namespace std;
const int N=1001000;
int n,a[N],b[N],f[N],g[N];

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	for (;T--;){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		f[1]=b[1];
		for (int i=2;i<=n;i++){
			f[i]=f[i-1];
			if (f[i]<a[i])f[i]=a[i];
			if (f[i]>b[i])f[i]=b[i];
		}
		g[n]=b[n];
		for (int i=n-1;i>=1;i--){
			g[i]=g[i+1];
			if (g[i]<a[i])g[i]=a[i];
			if (g[i]>b[i])g[i]=b[i];
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			int h=min(f[i],g[i]);
			ans+=max(h-a[i],0);
		}
		printf("%d\n",ans);
	}
	return 0;
}

