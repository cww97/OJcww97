/*
��ϯ�����������е�ÿһ��ǰ׺��һ�����������ֵΪ�±���߶���������Ҫ����ɢ������
��¼��ǰ׺��������ֵ�ֵ�Ĵ�����
����ɢ��ı��Ϊ1~n; ������ֱֵ����1~n����;�� 
��������[x,y]�ĵ�k���ֵ����ô��root[x-1],root[y]��ʼ��
t=root[y].[1,mid]-root[x-1].[1,mid] ,t��ʾ����[x,y]��ֵ��[1,mid]�ĸ��� 
���ж�t�Ƿ����K�����t����k,��ô˵��������[x,y]�ڴ���[1,mid]�����ĸ�������k,
Ҳ���ǵ�k���ֵ��[1,mid]�У�������[mid+1,r]�У�

������������ͬʱ��root[x-1],root[y]������
��l==rʱ ��k���ֵ������ɢ����Ϊl��ֵ��
 
���ÿ���߶ζ��������Ļ���n*(n<<2)�϶���mle��
���Ƿ��ֶ���ǰ׺[1,i]��ǰ׺[1,i+1]���߶��������b[i+1]<=mid (b[i+1]��ʾa[i+1]��ɢ��ı��)
��ô�߶���i���߶���i+1���������ȫ��ͬ�ģ���������Ҫ�ڽ���ֻ��Ҫ��ָ��ָһ�¾ͺã�
��ô����һ���µ��߶�����ʵ�������Ҫ���Ľڵ���Ϊlog(n)��nlog(n)�Ľڵ������ǿ������ܵ�;  
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
