#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=262144,M=131071;
//const int N=40,M=15;
int n,ans;

struct tree{
	int l[N],r[N],ma[N],mi[N],tag[N];
	
	void build(){
		memset(ma ,0,sizeof(ma ));
		memset(mi ,0,sizeof(mi ));
		memset(tag,0,sizeof(tag));
		for (int i=1+M;i<=M*2+1;i++)l[i]=r[i]=i-M;
		for (int i=M;i>=1;i--)l[i]=l[i<<1],r[i]=r[i<<1^1];
	}
	
	void down(int t){//无标记或叶子节点无需down 
		if ((!tag[t])||t>M)return ;
		ma[t<<1] = ma[t<<1^1]= ma[t];
		mi[t<<1] = mi[t<<1^1]= mi[t];
		tag[t<<1]=tag[t<<1^1]=tag[t];
		tag[t]=0;
	}
	
	void set(int t,int L,int R,int H){
		if (mi[t]>H)return;
		//printf("T%d:[%d,%d]:%d,%d,%d\n",t,l[t],r[t],ma[t],mi[t],tag[t]);
		if (L<=l[t]&&r[t]<=R&&ma[t]<=H){
			ans+=r[t]-l[t]+1;
			//printf("ans=%d\n",ans);
			ma[t]=mi[t]=tag[t]=H;
			return;
		}
		down(t);
		int mid=(l[t]+r[t])>>1;
		if (L<=mid)set(t<<1  ,L,R,H);
		if (mid< R)set(t<<1^1,L,R,H);
		ma[t]=max(ma[t<<1],ma[t<<1^1]);
		mi[t]=min(mi[t<<1],mi[t<<1^1]);
	}
}T;

int main(){
	//freopen("fuck.in","r",stdin);
	int cas;scanf("%d",&cas);
	while (cas--){
		scanf("%d",&n);
		T.build();
		ans=0;int L,R,H;
		while (n--){
			//printf("ask %d\n",n);
			scanf("%d%d%d",&L,&R,&H);
			R--;
			T.set(1,L,R,H);
			//printf("ans=%d\n",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
