#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,a,b,c,a1,a2,N;

LL gl (){ 
	if (n<b) return 0;
	LL ans=(n-b)/(b-c)+1;
	n-=ans*(b-c);
	return ans;
}

LL pl () {
	if (n<a)return 0;
	LL ans=n/a;
	n-=(n/a)*a;
	return ans;
}

int main(){
	while (cin>>n>>a>>b>>c){
		N=n; a1=gl()+pl();
		n=N; a2=pl()+gl();
		if (a1<a2) a1=a2;
		cout<<a1<<endl;
	}
	return 0;
}
