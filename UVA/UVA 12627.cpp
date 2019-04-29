/*
f[k][i]表示第k个小时前i行有多少个红球
当i在上半部分的时候，气球是复制的k-1的状态，只需 *2即可
。。。下。。。。。。，把上半区的全加上，再加上k-1时前（i-上半区行数）行的气球
c[k] = 第k个小时红色气球总数
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long LL;
using namespace std;
const int N=40000;
int i,k,a,b;
LL c[40];

LL f(int k,int i){
	if (i<=0)return 0;
	if (k==0)return 1;
	if (i<=(1<<(k-1)))return f(k-1,i)<<1;
	return c[k-1]*2+f(k-1,i-(1<<(k-1)));
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	c[0]=1;for (int i=1;i<=31;i++)c[i]=c[i-1]*3;
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d%d",&k,&a,&b);
		printf("Case %d: %lld\n",cas,f(k,b)-f(k,a-1));
	}
	return 0;
}
