#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long LL;
using namespace std;
const int N=1000000;
LL n,m,a[N],b[N],A,B;

LL gcd(LL x,LL y){
	if (!(x%y))return y;
	return gcd(x%y,y);
}

int main(){
	//freopen("fuck.in","r",stdin);
	cin>>n>>m;
	for (LL i=1;i*i<=n;i++){
		if (!(n%i)){
			a[++A]=i; a[++A]=n/i;
			if (i*i==n)A--;
		}
	}
	for (LL i=1;i*i<=m;i++){
		if (!(m%i)){
			b[++B]=i; b[++B]=m/i;
			if (i*i==m)B--;
		}
	}
	LL ans=0;
	for (int i=1;i<=A;i++){
		for (int j=1;j<=B;j++){
			if (a[i]==b[j]){ans++;break;}
		}
	}
	LL gc=gcd(A*B,ans);
	cout<<A*B/gc<<" "<<ans/gc<<endl;
	return 0;
} 
