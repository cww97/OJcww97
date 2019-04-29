#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=2333,BASE=100000007;
int a[N],n;
LL vis[N];
int gcd(int x,int y){
	if (y==0)return x;
	return gcd(y,x%y);
}
int main(){
	int T;scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
			for (int j=1;j<=1000;j++){
				if (!vis[j])continue;
				int t=gcd(a[i],j);
				vis[t]=(vis[t]+vis[j])%BASE;
			}
			vis[a[i]]++;
		}
		LL ans=0;
		for (int i=1;i<=1000;i++)
			ans=(ans+vis[i]*i%BASE)%BASE;
		cout<<ans<<endl;
	}
	return 0;
} 
