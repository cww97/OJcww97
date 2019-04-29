#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=230000;
int n,b,j,k,f,r;
long long sta[N],arr[N],dep[N],q[N];//start,arrive,deep

int main(){
	scanf("%d%d",&n,&b);
    f=0;r=-1;
    memset(sta,0x3f,sizeof(sta));
	for (int i=1;i<=n;i++){
		scanf("%I64d%I64d",&arr[i],&dep[i]);
		while (sta[q[f]]+dep[q[f]]<=arr[i])f++;
		if (r-f+1==0)sta[i]=arr[i],q[r=++f]=i;
		else if (r-f+1<=b)sta[i]=sta[q[r]]+dep[q[r]],q[++r]=i;
		else sta[i]=-1,dep[i]=0;
	}

	for (int i=1;i<n;i++)printf("%I64d ",sta[i]+dep[i]);
	printf("%I64d\n",sta[n]+dep[n]);
	return 0;
}
