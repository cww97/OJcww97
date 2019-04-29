#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const int N=50500;
int tree[N],n,x,y;
string st;

void add(int k,int num){
	while (k<=n){
		tree[k]+=num;
		k+=k&-k;//lowbit找父亲 
	}
}

int read(int k){
	int sum=0;
	while (k){
		sum+=tree[k];
		k-=k&-k;//lowbit,找儿子 
	}
	return sum;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d",&n);
		memset(tree,0,sizeof(tree));
		for (int i=1;i<=n;i++){
		    scanf("%d",&x);
			add(i,x);//原数组并不存在 
	    }
	    scanf("\n");
	    printf("Case %d:\n",cas);
	    int k=0;
	    for (;cin>>st&&st[0]!='E';){
	    	scanf("%d%d",&x,&y);
	    	if (st[0]=='Q')	printf("%d\n",read(y)-read(x-1));
	    	else if (st[0]=='A')add(x,y);
	    	else add(x,-y);
	    }
	}
	return 0;
} 
