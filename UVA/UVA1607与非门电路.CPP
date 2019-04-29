#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=233333;
struct gate{int x,y,z;}a[N*2];
int n,m;

int check(int x){
	for (int i=n-x;i<n;i++) a[i].z=1;
	for (int i=0;i<n-x;i++) a[i].z=0;
	for (int i=n+1;i<=n+m;i++){
		a[i].z=!(a[a[i].x].z&a[a[i].y].z);
	}
	return a[m+n].z;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	for (;T--;){
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		for (int i=1;i<=m;i++){
			//n-1~0为n个输入，n+1~n+m 为m个gate
			int x,y;scanf("%d%d",&x,&y);
			a[n+i].x=x+n;
			a[n+i].y=y+n;
		}
		int a0=check(0),a1=check(n),ans;
		if (a0==a1)ans=0;//常数
		else{
			int L=0,R=n;
			while(L<R){
				//if (L==R){ans=L;break;}
				int mid=(L+R)>>1;
				if (check(mid)==a1)R=mid;
				else L=mid+1;
			} ans=L;
		}
		for (int i=1;i<ans;i++)putchar('1');
		if (ans>=1)printf("x");
		for (int i=ans+1;i<=n;i++)putchar('0');
		puts("");
	}
	return 0;
}
