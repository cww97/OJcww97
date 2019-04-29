#include<cstdio>
#include<cstring>
#include<iostream> 
#include<algorithm>
using namespace std;
const int N=233333;
const int INF=1000000000;//9¸ö9 
int n,m,q,SUM,MIN,MAX,x1,x2,y1,y2,ask,x;

struct tree{
	int sum[N],ma[N],mi[N],set[N],add[N];
	
	void maintain(int t,int L,int R){
		int lc=t<<1,rc=lc+1;
		if (L<R){
			sum[t]=sum[lc]+sum[rc];
			mi[t]=min(mi[lc],mi[rc]);
			ma[t]=max(ma[lc],ma[rc]);
		}
		if (set[t]>=0){
			mi[t]=ma[t]=set[t];
			sum[t]=set[t]*(R-L+1);
		}
		if (add[t]){
			mi[t]+=add[t];
			ma[t]+=add[t];
			sum[t]+=add[t]*(R-L+1);
		}
	}
	
	void down(int t){
	    if (add[t]==0&&set[t]==-1)return ;
		int lc=t<<1,rc=lc+1;
		if (set[t]>=0){
			set[lc]=set[rc]=set[t];
			add[lc]=add[rc]=0;
			set[t]=-1;
		}
		if (add[t]){
			add[lc]+=add[t];
			add[rc]+=add[t];
			add[t]=0;
		}
	}
	
	void update(int t,int L,int R,int x){
		if (y1<=L&&R<=y2){
			if (ask==1)add[t]+=x;
			else {set[t]=x;add[t]=0;}
		}else{
		down(t);
		int lc=t<<1,rc=lc+1,mid=L+(R-L)/2;
		if (y1<=mid)update(lc,L,mid,x);else maintain(lc,L,mid);
		if (mid<y2)update(rc,mid+1,R,x);else maintain(rc,mid+1,R);	
		}
		maintain(t,L,R);
	}
	
	void query(int t,int L,int R,int ad){
		if (set[t]>=0){
			int w=set[t]+ad+add[t];
			SUM+=w*(min(R,y2)-max(L,y1)+1);
			MIN=min(MIN,w);
			MAX=max(MAX,w);
		}
		else if (y1<=L&&R<=y2){
			SUM+=sum[t]+(R-L+1)*ad;
			MIN=min(MIN, mi[t]+ad);
			MAX=max(MAX, ma[t]+ad);
		}
		else {
			int mid=L+(R-L)/2,lc=t<<1,rc=lc+1;
		    if (y1<=mid)query(lc,L,mid,add[t]+ad); 
		    if (mid<y2)query(rc,mid+1,R,add[t]+ad);
		}
	}
}T[30];

int main(){
	//freopen("fuck.in","r",stdin);
	for (;scanf("%d%d%d",&n,&m,&q)==3;){
		memset(T,0,sizeof(T));//init
		for (int i=1;i<=n;i++){
			memset(T[i].set,-1,sizeof(T[i].set));
			T[i].set[1]=0;
		}
		for (;q--;){//work
			scanf("%d%d%d%d%d",&ask,&x1,&y1,&x2,&y2);
			if (ask==3){
				SUM=0;MIN=INF;MAX=-INF;
				for (int i=x1;i<=x2;i++){
					T[i].query(1,1,m,0);
				}
				printf("%d %d %d\n",SUM,MIN,MAX);
			}else{
				scanf("%d",&x);
				for (int i=x1;i<=x2;i++){
					T[i].update(1,1,m,x);
				}
			}
		}
	}
	return 0;
}
