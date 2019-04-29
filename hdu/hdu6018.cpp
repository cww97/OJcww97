#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N=10086,oo=0x3f3f3f3f;
int n,m;
int L[N],R[N];
map<int,vector<int> >mop;
multiset<int> sot;
int main(){
 //   freopen("1.in","r",stdin);
 //   freopen("1.out","w",stdout);
    int T;
    for (scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        int tmpn=1;
        scanf("%d%d",&L[1],&R[1]);
        for (int i=2;i<=n;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            if (l!=R[tmpn]+1&&l!=R[tmpn]) L[++tmpn]=l,R[tmpn]=r;
            else R[tmpn]=r;
        }
        n=tmpn;
        mop.clear();
        for(int i=1;i<=n;i++) mop[R[i]+1].clear();
        for (int i=1;i<=m;i++){
            int l,r,d;
            scanf("%d%d%d",&l,&r,&d);
            if (r-l+1<d) continue;
            mop[l].push_back(d);
            mop[r-d+2].push_back(-d);
        }
        sot.clear();
        auto t=mop.begin();
        int ans=0;
        for (int i=1;i<=n;i++){
            for (;t!=mop.end()&&t->first<=L[i];t++){
                for (auto d: t->second){
                    if (d>0) sot.insert(d);
                    else sot.erase(sot.find(-d));
                }
            }
            int pre=L[i],re=oo;
            for (;t!=mop.end()&&t->first<=R[i]+1;t++){
                int len=t->first-pre;
                pre=t->first;
                if (re!=oo){
                    int can=min(re,len);
                    len-=can;
                    re-=can;
                    if (re==0) ans++,re=oo;
                }
                if (re==oo&&!sot.empty()){
                    int d=*sot.begin();
                    ans+=len/d;
                    re=len%d;
                    if (re) re=d-re;
                    else re=oo;
                }
                for (auto d: t->second){
                    if (d>0) sot.insert(d);
                    else sot.erase(sot.find(-d));
                }
                if (!sot.empty()) re=min(re,*sot.begin());
            }
        }
        printf("%d\n",ans);
    }
}
