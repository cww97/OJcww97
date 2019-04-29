#include<cstdio>//cww
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=233333;
struct node{
	int num,cnt,L,R;
	node(int num=0,int cnt=0,int L=0,int R=0)
	    :num(num),cnt(cnt),L(L),R(R){}
}a[N];
int n,q,x,A,f[N],by[N][20],ans;

int st(int l,int r){
	if (l>r)return 0;
	int t=0,len=r-l+1;
	while (1<<(t+1) <=len) t++;
	return max(by[l][t],by[r-(1<<t)+1][t]);
}

int main(){
	freopen("fuck.in","r",stdin);
	for (;~scanf("%d",&n)&&n;){
		//readln
		scanf("%d",&q);
		a[A=0].num=INT_MAX;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			if (x==a[A].num){
				a[A].cnt++;
				a[A].R=i;
			}else a[++A]=node(x,1,i,i);
			f[i]=A;
		}
		//make st±í
		for (int i=1;i<=A;i++) by[i][0]=a[i].cnt;
		for (int j=1;(1<<j)<=A;j++){
			for (int i=1;i+(1<<j)<=A;i++){
				by[i][j]=max(by[i][j-1],by[i+(1<<(j-1))][j-1]);
			}
		}
		//solve 
		for (int i=1;i<=q;i++){
			int L,R;scanf("%d%d",&L,&R);
			if (f[L]==f[R]) ans=R-L+1;
			else {
			    ans=max(a[f[L]].R-L+1,R-a[f[R]].L+1);
			    ans=max(ans,st(f[L]+1,f[R]-1));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
