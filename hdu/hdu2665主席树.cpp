/*
主席树：对于序列的每一个前缀建一棵以序列里的值为下标的线段树（所以要先离散化），
记录该前缀序列里出现的值的次数；
记离散后的标记为1~n; （下面值直接用1~n代替;） 
对于区间[x,y]的第k大的值，那么从root[x-1],root[y]开始，
t=root[y].[1,mid]-root[x-1].[1,mid] ,t表示区间[x,y]内值在[1,mid]的个数 
先判断t是否大于K，如果t大于k,那么说明在区间[x,y]内存在[1,mid]的数的个数大于k,
也就是第k大的值在[1,mid]中，否则在[mid+1,r]中；

这样我们依次同时从root[x-1],root[y]往下走
当l==r时 第k大的值就是离散后标记为l的值；
 
如果每棵线段都建完整的化，n*(n<<2)肯定会mle，
我们发现对于前缀[1,i]和前缀[1,i+1]的线段树，如果b[i+1]<=mid (b[i+1]表示a[i+1]离散后的标记)
那么线段树i和线段树i+1的左边是完全相同的，根本不需要在建，只需要用指针指一下就好；
那么对于一棵新的线段树其实我们最多要建的节点数为log(n)；nlog(n)的节点数还是可以忍受的;  
*/
# include <cstdio>
# include <iostream>
# include <algorithm>
# define N 100100
using namespace std;
int i,n,m,root[N],a[N],p[N],b[N],cnt;
struct node{int lc,rc,w;}T[N*30];
bool cmp(int i,int j){return a[i]<a[j];}

void build(int &rot,int l,int r,int x){
	T[++cnt]=T[rot];rot=cnt;
	T[cnt].w++;
	if (l==r)return ;
	int mid=(l+r) >> 1;
	if (x<=mid)build(T[cnt].lc,l,mid,x);
	else build(T[cnt].rc,mid+1,r,x);
}

int query(int x,int y,int l,int r,int k){
	if (l==r)return l;
	int t=T[T[y].lc].w-T[T[x].lc].w;
	int mid=(l+r) >> 1;
	if (t>=k)return query(T[x].lc,T[y].lc,l,mid,k);
	else return query(T[x].rc,T[y].rc,mid+1,r,k-t);
}

int main(){
	freopen("fuck.in","r",stdin);
	int cas;scanf("%d",&cas);
	for (;cas--;){
		root[0]=0;cnt=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		  {scanf("%d",&a[i]);p[i]=i;}
		sort(p+1,p+n+1,cmp);
		for (int i=1;i<=n;i++)b[p[i]]=i;
		for (int i=1;i<=n;i++){
			root[i]=root[i-1];
			build(root[i],1,n,b[i]);
		}
		for (int i=1;i<=m;i++){
			int x,y,k; scanf("%d%d%d",&x,&y,&k);
			int t=query(root[x-1],root[y],1,n,k);
			printf("%d\n",a[p[t]]);
		}
	}
	return 0;
} 
