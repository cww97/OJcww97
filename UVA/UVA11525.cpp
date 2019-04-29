#include<cstdio>
#include<cstring>
#include<iostream> 
#include<algorithm>
using namespace std;
const int N=140000;
int ans;

struct tree{
    int su[N],l[N],r[N],M;
    
    void build(int n){
    	M=1; while(M<n)M<<=1; M--;
    	for (int i=M+1;i<=M+n;i++)l[i]=r[i]=i-M,su[i]=1;
    	for (int i=M+n+1;i<=M*2+1;i++)l[i]=r[i]=i-M,su[i]=0;
    	for (int i=M;i>=1;i--){
    		l[i]=l[i<<1],r[i]=r[i<<1^1];
    		su[i]=su[i<<1]+su[i<<1^1];
    	}
    }
    
    void get(int t,int k,int sum){
    	if (l[t]==r[t]){
    		ans=l[t];su[t]=0;return;
    	}
    	int mid=(l[t]+r[t])>>1;
    	if (sum+su[t<<1]>=k)get(t<<1,k,sum);
    	else get(t<<1^1,k,sum+su[t<<1]);
    	su[t]=su[t<<1]+su[t<<1^1];
    }
}T;

int main(){
	int cas;scanf("%d",&cas);
	while (cas--){
		int n;scanf("%d",&n);
		T.build(n);
		for (int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			T.get(1,x+1,0);
			printf("%d",ans);
			if (i<n)printf(" "); 
		}
		puts("");
	}
	return 0;
}
