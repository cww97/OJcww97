#include<cstdio>
#include<iostream>
int x,n,A=0;
long long ans,a[110];
using namespace std;
int main(){
	while (~scanf("%d",&n)){	
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x==1)a[++A]=i;
	}
	ans=1;
	for (int i=2;i<=A;i++)
	  ans=ans*(a[i]-a[i-1]);
	if (A==0) ans=0;
	cout<<ans<<endl;
	A=0;
	}
	return 0;
} 
