#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while (scanf("%d",&n)==1){
		int x,Max=0,Min=999;
		double sum=0;
		for (int i=0;i<n;i++){
			scanf("%d",&x);
			sum+=x;
			Max=max(Max,x);
			Min=min(Min,x);
		}
		sum-=Max+Min;
		sum/=n-2;
		printf("%.2lf\n",sum);
	}
	
	return 0;
} 
