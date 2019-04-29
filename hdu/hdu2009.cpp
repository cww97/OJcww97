#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int m;
double n,ans;
int main(){
	while (scanf("%lf%d",&n,&m)==2){
		ans=n;m--;
		while (m--){
			ans+=(n=sqrt(n));
		}
		printf("%.2lf\n",ans);
	}
	return 0;
} 
