#include<iostream>
#include<cstdio>
using namespace std;
int T,n,x,i,sum;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        sum=0;
        scanf("%d",&n);
        for (i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        printf("%d\n",sum);
    }
    return 0;
}
