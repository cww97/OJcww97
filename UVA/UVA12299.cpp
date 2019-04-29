#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=433333,INF=99999999; 

struct tree{
	int T[N],BTM;
	
	void build(int n){
	    BTM=1; while (BTM<n)BTM<<=1; BTM--;//getBTM
	    for (int i=BTM+1;i<=BTM+n;i++)scanf("%d",&T[i]);
	    scanf("\n");
	    for (int i=BTM+n+1;i<=BTM*2+1;i++)T[i]=INF;
	    for (int i=BTM;i>=1;i--){
		    T[i]=min(T[i<<1],T[i<<1^1]);
	    }
    }
    
    int query(int l,int r){
	    int ans=INF;
    	for (l+=BTM-1,r+=BTM+1;l^r^1;l>>=1,r>>=1){
	    	if (~l&1)ans=min(ans,T[l^1]);
		    if ( r&1)ans=min(ans,T[r^1]);
	    }
	    return ans;
    }
    
    void change(int k,int x){
	    for (T[k+=BTM]=x,k>>=1;k;k>>=1){
		    T[k]=min(T[k<<1],T[k<<1^1]);
	    }
    }
}T;

int main(){
	int x,y,n,q;
	//freopen("fuck.in","r",stdin);
	scanf("%d%d",&n,&q);
	T.build(n);
	
	char ch,ch2,ask;
	while (q--){
		scanf("%c",&ask);
		for (int i=1;i<=5;i++)scanf("%c",&ch);
		if (ask=='q'){
			scanf("%d%c%d%c",&x,&ch,&y,&ch2);
			printf("%d\n",T.query(x,y));
		}else {
			scanf("%d%c",&x,&ch);
			int tmp=T.T[x+T.BTM];
			while (~scanf("%d%c",&y,&ch)){
				T.change(x,T.T[y+T.BTM]);
				x=y; if (ch==')')break;
			}
			T.change(y,tmp);
		}
		getchar();
	}
	return 0;
} 
