#include<iostream>
#include<cstdio>
using namespace std;
int T,a,b;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",a+b);
    }
    return 0;
}
