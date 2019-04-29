#include<iostream>//还没有写完 
#include<cstdio>
#include<algorithm>
using namespace std;
int i,n,a[300],s[300]
int ff1[300][300],ff2[300][300];

int f1(int l,int r){
	if (l==r)return 0;
	if (ff1[l,r]>0)return ff1[l,r];
	int dk=
	for (int i=l;i<=r-1;i++){
		
	}
	
}

int main (){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for (int i=1;i<=n;i++){
		a[i+n]=a[i];
		s[i+n]=s[i+n-1]+a[i+n];
	}
	int hk,maxhk=0,minhk=99999999;
	for (int i=1;i<=n;i++){
		minhk=min(minhk,f1(i,i+n-1));
		maxhk=max(maxhk,f2(i,i+n-1));
	}
	printf("%d\n%d\n",minhk," ",maxhk);
}
