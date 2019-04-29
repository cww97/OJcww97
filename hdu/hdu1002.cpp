#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include <string.h>
using namespace std;
int a[10000],b[10000],c[10000],n,x;
string st1,st2;

int main ()
{
	scanf("%d",&n);
	for (int time=1;time<=n;time++)
	{
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>st1>>st2;
		a[0]=st1.size();
		b[0]=st2.size();
		c[0]=max(a[0],b[0]);
		for (int i=1;i<=a[0];i++)a[i]=st1[a[0]-i]-'0';
		for (int i=1;i<=b[0];i++)b[i]=st2[b[0]-i]-'0';
		for (int i=1;i<=c[0];i++)
		{
			x=a[i]+b[i]+c[i];
			c[i]=x%10;
			c[i+1]=x/10;
		}
		if (c[c[0]+1]>0)c[0]++;
		printf("Case %d:\n",time);
		for (int i=a[0];i>=1;i--)printf("%d",a[i]);
		printf(" + ");
		for (int i=b[0];i>=1;i--)printf("%d",b[i]);
		printf(" = ");
		for (int i=c[0];i>=1;i--)printf("%d",c[i]);
		//if (time<n)printf("\n\n");
		if (time==n)printf("\n");
		else printf("\n\n");
	}
	return 0;
} 
