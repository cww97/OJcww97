#include<iostream>
#include<cstdio>
using namespace std;

int main (){
	int n,x,sum=0;
	scanf("%d",&n);
	for (int i=1; i<=n;i++){
		scanf("%d",&x);
		sum+=x;
	}
	printf("%d\n",sum);
	return 0;
}
