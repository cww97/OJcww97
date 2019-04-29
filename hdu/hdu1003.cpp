#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
using namespace std;
int T,i,n,ans,tt,t;
int a[100010],f[100010],s[100010];

int main()
{
	freopen("fuck.in","r",stdin);
	freopen("fuck.out","w",stdout);
	scanf("%d",&T);
	for (tt=1;tt<=T;tt++)
	{
		scanf("%d",&n);
		ans=INT_MIN;
		s[0]=1;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (f[i-1]+a[i]<a[i])
			{f[i]=a[i];s[i]=i;}
			else{f[i]=f[i-1]+a[i]; s[i]=s[i-1];}
			if (f[i]>ans){ans=f[i];t=i;}
		}
		if (tt==T)printf("Case %d:\n%d %d %d\n",tt,ans,s[t],t);
		else printf("Case %d:\n%d %d %d\n\n",tt,ans,s[t],t);
	}
	return 0;
}
