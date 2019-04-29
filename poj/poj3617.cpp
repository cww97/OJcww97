#include<cstdio>
using namespace std;
int n,i,l,r,j,k,s;
char st[2010],ans[2010],ch;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	    scanf("%c%c",&ch,&st[i]);
	scanf("%c",&ch);
	l=1;r=n;s=0;
	while (l<=r)
	{
		s++;
		if (st[l]<st[r]){ans[s]=st[l];l++;}
		else if (st[r]<st[l]) {ans[s]=st[r];r--;}
		else {
			for (j=1;j<=(r-l+1)/2;j++)
			    if (st[l+j]!=st[r-j])break;
			if (st[l+j]<st[r-j]) {ans[s]=st[l];l++;}
			else {ans[s]=st[r];r--;}
		}
	}
	for (i=1;i<=s;i++)
	{
		printf("%c",ans[i]);
		if (i%80==0&&i<n-1)printf("\n");
	}
	return 0;
} 
