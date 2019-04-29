#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int l,r,n,i,w[1000],s[1000],ff[1000][1000];

int f(int l,int r){
	if (ff[l][r]>0)return ff[l][r];
	if (l==r) return 0;
	int dk=99999999;
	for(int i=l;i<=r-1;i++){
		dk=min(f(l,i)+f(i+1,r),dk);
	}
	ff[l][r]=dk+s[r]-s[l-1];
	return ff[l][r];
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
	   scanf("%d",&w[i]);
	   s[i]=s[i-1]+w[i];
	}
	
	printf("%d\n",f(1,n));
	return 0;
}
