#include<cstdio>
#include<algorithm>
using namespace std;
int T,l,n,i,x,mi,ma;

int main ()
{
	scanf("%d",&T);
	while (T--)
	{
		ma=0; mi=0;
		scanf("%d%d",&l,&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mi=max(mi,min(x,l-x));
			ma=max(ma,max(x,l-x));
		}
		printf("%d %d\n",mi,ma);
	}
	return 0;
} 
