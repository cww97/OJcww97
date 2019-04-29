#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=233333,nn=200000;
int n,c[N],m,t[N];

void add(int k,int x){
    while(k<=nn){
	    c[k]+=x;
		k+=k&-k;
	}
}

int sum(int k){
    int s=0;
	while (k){
	    s+=c[k];
		k-=k&-k;
	}
	return s;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		memset(c,0,sizeof(c));
		for (int i=1;i<nn;i++){
			t[i]=n-i+1;
		}
		for (int i=1;i<=n;i++){
			add(i,1);
		}
		
		while (m--){
			int x;scanf("%d",&x);
			printf("%d",sum(n)-sum(t[x]));
			if (m)printf(" ");
			add(t[x],-1);
			t[x]=++n;
			add(n,1);
		}
		puts("");
	}
	return 0;
} 
