#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		if (n&1)printf("%d\n\n",((n+1)/2)*n);
		else printf("%d\n\n",(n/2)*(n+1));
    }
    return 0;
}
