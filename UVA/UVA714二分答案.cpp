# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# define LL long long
using namespace std;
const int M=10001000;
int pa[M],m,k,ma;//pages,m books,k scribers
bool sl[M];//slash
LL mid,group;

bool check(LL x){
	if (x<ma)return 0;
	memset(sl,0,sizeof(sl));
	LL re=0;group=1;
    for (int i=m;i>=1;i--)
        if (re+pa[i]>x) {group++;re=pa[i];sl[i]=1;}
        else re+=pa[i];
    return group<=k;
}

int main(){
	freopen("fuck.in","r",stdin);
	//freopen("fuck.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&k);
		int l=M*2,zz=0;ma=0;
		long long r=0;
		for (int i=1;i<=m;i++){
		    scanf("%d",&pa[i]);
		    ma=max(ma,pa[i]);
		    r+=pa[i];
	    }
	    l=ma;
	    while(l<r){//二分啊 
	    	mid=(l+r)>>1;
	    	if (check(mid))r=mid;
	    	else l=mid+1;
	    	//printf("l=%d r=%d check(%d)=%d\n",l,r,mid,check(mid));
	    }
	    
	    bool tmp=check(l);//每个人都要有任务
	    //printf("ans=%d group=%d k=%d\n",l,group,k);
	    if (group<k) for (int i=1;i<=m&&zz<k-group;i++)
	    		         if (!sl[i]){sl[i]=1;zz++;}
		for (int i=1;i<m;i++){
			printf("%d ",pa[i]);
			if (sl[i]) printf("/ ");
		}
		printf("%d\n",pa[m]);
	}
	return 0;
}
