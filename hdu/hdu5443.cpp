#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;
int ti,t,n,q,nn,l,r,f[10000][300];

int main()
{
	freopen("fuck.in" ,"r",stdin);
	//freopen("fuck.out","w",stdout);
	scanf("%d",&ti);
	while (ti--)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n); nn=(int)log2(n)+1;
		for (int i=1;i<=n ;i++) scanf("%d",&f[i][0]);
		for (int j=1;j<=nn;j++)
		    for (int i=1;i<=n;i++)
		        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		scanf("%d",&q);
		while (q--)
		{
			scanf("%d%d",&l,&r);
			t=log2(r-l+1);
			printf("%d\n",max(f[l][t],f[r-(1<<t)+1][t]));
		}
	}
	return 0;
} 
