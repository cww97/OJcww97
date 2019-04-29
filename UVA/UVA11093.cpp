#include<cstdio>
#include<iostream>
using namespace std;
const int N=200200;
int i,n,st,p[N],q[N];

bool check(int x){
	int gas=p[x];
	for (int i=x+1;i<=x+n;i++){
		gas-=q[i-1];
		if (gas<0){st=i;return 0;}
		gas+=p[i];
	}
	return 1;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T; scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		printf("Case %d: ",cas);
		st=0; scanf("%d",&n);
		for (i=1;i<=n;i++){scanf("%d",&p[i]);p[i+n]=p[i];}
		for (i=1;i<=n;i++){scanf("%d",&q[i]);q[i+n]=q[i];}
		bool ok=0;//work begin
		for (i=1;i<=n;i++){
			if (!check(i))i=st-1;
			else {ok=1;break;}
	    }
		if (ok)printf("Possible from station %d\n",i);
		else puts("Not possible");
	}
	
	return 0;
} 
