#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int r,n,i,nn,x,a[1010],l,p,ans;
bool v[1010];
int main ()
{
	freopen("fuck.in","r",stdin);
	while(~scanf("%d%d",&r,&n))
	{
		if ((n==-1)&&(r==-1))break;
		memset(v,0,sizeof(v)); nn=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if (v[x]) continue;
			v[x]=true;
			nn++; a[nn]=x;
		}
		sort(a+1,a+nn+1);
		i=1;ans=0;
		while (i<=nn)
		{
			l=a[i];
			while (i<=nn&&a[i]<=l+r)i++;
			p=a[i-1];
			while (i<=nn&&a[i]<=p+r)i++;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
