#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=205;
LL a[MAXN];
LL dp[2][205][6000];
//从前i个数中选j个数且5的次幂为r所能得到的最多的2
//the roundness of the number is determined by minimum of powers of 2 and 5 in the number

int getpower(LL x,int p)
{
    int res=0;
    while(x%p==0) x/=p,++res;
    return res;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        memset(dp,-1,sizeof(dp));
        dp[0][0][0]=0;
        int cur=0,five,two;
        LL sum=0;
        for(int i=1;i<=n;++i)
        {
            five=getpower(a[i],5);two=getpower(a[i],2);
            sum+=five;
            cur^=1;
            for(int j=0;j<=i&&j<=k;++j)
            {
                for(int r=0;r<=sum;++r)
                {
                    dp[cur][j][r]=max(dp[cur][j][r],dp[cur^1][j][r]);
                    if(j>=1&&r-five>=0&&dp[cur^1][j-1][r-five]>=0)
                        dp[cur][j][r]=max(dp[cur][j][r],dp[cur^1][j-1][r-five]+two);
                }
            }
        }
        LL ans=0;
        for(int r=0;r<=sum;++r)
            ans=max(ans,min((LL)r,dp[cur][k][r]));
        printf("%lld\n",ans);
    }
    return 0;
}
