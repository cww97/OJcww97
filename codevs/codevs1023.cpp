#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n,x,sum2=0;
	double xx,sum1=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%lf",&x,&xx);
		sum1+=x*xx;
		sum2+=x;
	}
	printf("%.2lf",sum1/(sum2));
	return 0;
}
