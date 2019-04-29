#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=3333;
bool prime[N];

void get_prime(){
	memset(prime,1,sizeof(prime));
	prime[1]=0;
	for (int i=2;i<N;i++){
		if (prime[i]){
			for (int j=i+i;j<N;j+=i)
				prime[j]=0;
		}
	}
}

int main(){
	get_prime();
	int x,y;
	while (scanf("%d%d",&x,&y)==2&&!(!x&&!y)){
		bool ok=true;
		for (int i=x;i<=y;i++)
			if (!prime[i*i+i+41]){ok=0;break;}
		if (ok)puts("OK");
		else puts("Sorry");
	}
	
}
