#include<cstdio>//cww=2016.3.6
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
const int N=1000100;
int QL,QR;
LL s[N];
LL sum(int L,int R){return s[R]-s[L-1];}
LL sum(pa x){return sum(x.first,x.second);}
pa better(pa a,pa b){
	if (sum(a)!=sum(b))return sum(a)>sum(b)?a:b;
	return a<b?a:b;
}

struct tree{
	int pre[N],suf[N];pa sub[N];
	
	void build(int t,int L,int R){
		if (L==R){
			pre[t]=suf[t]=L;
			sub[t]=make_pair(L,L);
			return ;
		}
		int lc=t<<1,rc=lc+1,mid=L+(R-L)/2;
		build(lc,L,mid);                     //×ÓÊ÷ 
		build(rc,mid+1,R);
		LL x=sum(L,pre[lc]);//pre
		LLy=sum(L,pre[rc]);
	    if (x==y)pre[t]=min(pre[lc],pre[rc]);
	    else pre[t]=x>y?pre[lc]:pre[rc];
	    x=sum(suf[lc],R);//suf
		y=sum(suf[rc],R);
	    if (x==y)suf[t]=min(suf[lc],suf[rc]);
	    else suf[t]=x>y?suf[lc]:suf[rc];
	    sub[t]=better(sub[lc],sub[rc]);      //sub
	    sub[t]=better(sub[t],make_pair(suf[lc],pre[rc]));
	}
	
	pa querypre(int t,int L,int R){
		if (pre[t]<=QR)return make_pair(L,pre[t]);
		int mid=L+(R-L)/2,lc=t<<1,rc=lc+1;
		if (QR<=mid)return querypre(lc,L,mid);
		pa x=querypre(rc,mid+1,R);
		x.first=L;
		return better(x,make_pair(L,pre[lc]));
	}
	
	pa querysuf(int t,int L,int R){
		if (QL<=suf[t])return make_pair(suf[t],R);
		int mid=L+(R-L)/2,lc=t<<1,rc=lc+1;
		if (mid<QL)return querysuf(rc,mid+1,R);
		pa x=querysuf(lc,L,mid);
		x.second=R;
		return better(x,make_pair(suf[rc],R));
	}
	
	pa query(int t,int L,int R){
		if (QL<=L&&R<=QR)return sub[t];
		int mid=L+(R-L)/2,lc=t<<1,rc=lc+1;
		if (QL<=mid)return query(lc,L,mid);
		if (mid<QR)return query(rc,mid+1,R);
		pa x=querypre(rc,mid+1,R);
		pa y=querysuf(lc,L,mid);
		pa z=better(query(lc,L,mid),query(rc,mid+1,R));
		return better(z,make_pair(y.first,x.second));
	}
}T;
int main(){
	//freopen("fuck.in","r",stdin);
	int cas=0,n,x,q;
	while (scanf("%d%d",&n,&q)==2){
		s[0]=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			s[i]=s[i-1]+x;
		}
		T.build(1,1,n);
		printf("Case %d:\n", ++cas);
		while (q--){
			int L,R;scanf("%d%d",&L,&R);
			QL=L;QR=R;
			pa ans=T.query(1,1,n);
			printf("%d %d\n",ans.first,ans.second);
		}
	}
	return 0;
}
