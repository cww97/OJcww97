#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1010;
int n,a[N],b[N];
int main(){
	//freopen("fuck.in","r",stdin);
	while (scanf("%d",&n)==1){
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		if (n&1){
			for (int i=1;i*2<=n+1;i++)b[i*2-1]=a[i];
			for (int i=n/2+2;i<=n;i++)b[(i-(n+1)/2)*2]=a[i];
		}else{
			for (int i=1;i*2<=n;i++)b[i*2-1]=a[i];
			for (int i=n/2+1;i<=n;i++)b[(i-n/2)*2]=a[i];
		}
		for (int i=1;i<n;i++)printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
	return 0;
} 
