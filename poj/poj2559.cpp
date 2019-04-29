#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long LL;
const int N=1e5+10;
LL L[N],R[N],h[N],sta[N];
using namespace std;
int main(){
    //freopen("fuck.in","r",stdin);
    for (int n;~scanf("%d",&n)&&n;){
        for (int i=1;i<=n;i++)scanf("%I64d",&h[i]);
        h[0] = h[n+1] = 0;
        int top = 0;
        for (int i=1;i<=n+1;i++){
            for (;1;){
                int pos = sta[top];
                if (h[pos]<=h[i])break;
                R[pos]=i;
                top--;
            }
            L[i] = sta[top];
            sta[++top] = i ;
        }
        LL ans = 0;
        for (int i=1;i<=n;i++)
            ans=max(ans,h[i]*(R[i]-L[i]-1));
        printf("%I64d\n",ans);
    }
    return 0;
}
