/*
����:CWW970329
��Ŀ:p3064 ���
*/
#include <stdio.h>
const int N = 5000000;
int main()
{
    int i;
    double x, sum = 0;;
    scanf("%lf",&x);
    for (i=1;i<=N;i++){
        sum += 1.0/i;
        if(sum>=x)break;
    }
    if (sum>=x)printf("%d\n",i);
    else puts("Error!");
    return 0;
}
