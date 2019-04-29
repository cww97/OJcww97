#include<iostream> 
#include<cstdio>
using namespace std;
int n,m,l,r,BTM=1;
int trl[1000000],trr[1000000],trw[1000000];

void change(int t){
	if (trw[t]==0) return;
	if ((l<=trl[t])&&(r>=trr[t])){trw[t]=0;return;}
	int mid=trr[t<<1];
	if (l<=mid) change(t<<1);
	if (r> mid) change(t*2+1);
	trw[t]=trw[t<<1]+trw[(t<<1)^1];
}

int main(){
	scanf("%d%d",&n,&m);
	while (BTM<n) BTM=BTM<<1;
	BTM--;
	for (int i=1;i<=n;i++){
		trl[i+BTM]=i;
		trr[i+BTM]=i;
		trw[i+BTM]=1;
	}
	for (int i=n+1;i<=BTM+1;i++){
		trl[i+BTM]=i;
		trr[i+BTM]=i;
	}
	for (int i=BTM;i>=1;i--){
		trl[i]=trl[i<<1];
		trr[i]=trr[i<<1^1];
		trw[i]=trw[i<<1]+trw[i<<1^1];
	}
	
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		change(1);
		printf("%d\n",trw[1]);;
	}
	return 0;
}
