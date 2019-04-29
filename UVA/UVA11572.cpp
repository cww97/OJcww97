#include<set>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1000100;
int i,n,a[N];
int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	for (;T--;){
		scanf("%d",&n);
		for (i=0;i<n;i++)scanf("%d",&a[i]);
		int l=0,r=0,ans=0;
		set<int>s; 
		while(r<n){
			while (r<n&&!s.count(a[r]))s.insert(a[r++]);
			ans=max(ans,r-l);
			s.erase(a[l++]);
		}
		printf("%d\n",ans);
	} 
	return 0;
} 
