#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=233333;
int i,n,a[N],last[N],next[N];

bool check(int l,int r){
	if (l>=r)return 1;
	int dep=(r-l+1)>>1;
	for (int i=1;i<=dep;i++){
	  if (last[l+i]<=l-1&&next[l+i]>=r+1)
		return check(l,l+i-1)&&check(l+i+1,r);
	  if (last[r-i]<=l-1&&next[r-i]>=r+1)
		return check(l,r-i-1)&&check(r-i+1,r);
	}
	return 0;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	for (;T--;){
		scanf("%d",&n);
		map<int,int>mp;
		for (i=1;i<=n;i++){
			last[i]=0; 
			next[i]=n+1;
		} 
		for (i=1;i<=n;i++){
			scanf("%d",&a[i]);
			last[i]=mp[a[i]];
			next[last[i]]=i;
			mp[a[i]]=i;
		}
		puts(check(1,n)?"non-boring":"boring");
	}
	return 0;
}
