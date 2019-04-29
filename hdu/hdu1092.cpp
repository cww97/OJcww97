#include<iostream>
#include<cstdio>
using namespace std;
int n,x,i,sum;
int main()
{
    scanf("%d",&n);
    while (n>0)
    {
        sum=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        printf("%d\n",sum);
        scanf("%d",&n);
    }
    return 0;
}
