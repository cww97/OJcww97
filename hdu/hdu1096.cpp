#include<iostream>
#include<cstdio>
using namespace std;

int main ()
{
	int n,x; scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int m,x,sum=0; scanf("%d",&m);
		for (int j=1;j<=m;j++)
		{scanf("%d",&x);sum+=x;}
		if (i==n)printf("%d\n",sum);
		else printf("%d\n\n",sum);
	}
	return 0;
}
