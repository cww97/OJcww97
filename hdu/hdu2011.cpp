#include<cstdio>
#include<iostream>
using namespace std;

double f(int n){
	int tag=-1;
	double sum=0;
	for (int i=1;i<=n;i++){
		tag=-tag;
		sum+=1.0*tag*(1.0/i);
	} 
	return sum;
}

int main(){
	int q;scanf("%d",&q);
	while (q--){
		int n;scanf("%d",&n);
		printf("%.2lf\n",f(n));
	}
	return 0;
} 
