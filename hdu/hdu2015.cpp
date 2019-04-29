#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		int sum=0;
		for (int i=1;i<=n;i++){
			sum+=(i<<1);
			if(i%m==0){
				if (i!=m)printf(" ");
				printf("%d",sum/m);
				sum=0;
			}
		}
		if (n%m!=0){
			printf(" %d",sum/(n%m));
		}
		puts("");
	}
	return 0;
}