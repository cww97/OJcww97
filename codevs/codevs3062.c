/*
 *codeVs 3062
 *by cww97
 */
#include <stdio.h>
int power(int a,int b)//a^b
{
    int ret = 1;
    for (;b--;) ret *= a;
    return ret;
}

int fun(int p)
{
    int top = 0, a[22];
    while( p > 0 ){
        a[top++] = p % 10;
        p /= 10;
    }
    int i, sum = 0;
    for(i=0;i<top;i++){
       sum += power(a[i],top);
    }
    return sum;
}

int main()
{
    int m,n,i;
    scanf("%d%d", &m, &n);
    int ok = 0;
    for(i=m;i<=n;i++){
        if(i==fun(i)){
            printf("%d\n",i);
            ok = 1;
        }
    }
    if (!ok) puts("No solution!");
    return 0;
}
