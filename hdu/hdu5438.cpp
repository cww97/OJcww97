#include<iostream>
#include<cstdio>
using namespace std;
int w[200000],s[200000];
bool v[10000]

void link(int x,int y)
{
	cnt++;
	e[cnt]=y;
	s[x]++;
	ne[cnt]=head[x];
	la[head[x]]=cnt;
	head[x]=cnt;
}

void bfs1(int x)
{
	v[x]=true;
	if (s[x]=0) return;
	int f=1;r=1;
	q[1]=x;
	while (f<=r)
	{
		int k=head[q[f]];
		if (s[q[f]])
		f++;
	}
	
}

int main ()
{
	int t; scanf("%d",&t);
	while (t--)
	{
		int ans=0,p,m,x,y,cnt=0;
		memset(v,0,sizeof(v));
		memset(s,0,sizeof(s));
		scanf("%d%d",&p,&m);
		for (int i=1;i<=p;i++) scanf("%d",&w[i]);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			link(x,y); link(y,x);
		}
		for (int i=1;i<=p;i++;s[i]<=1) bfs1(i);
		for (int i=1;i<=p;i++;!v[i]) bfs2(i);
		printf("%d\n",ans);
	}
	return 0;
} 
