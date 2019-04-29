#include<cstdio>
#include<iostream>
using namespace std;
int n,x,ans;
int main(){
	while (scanf("%d",&n)==1){
		ans=1;
		for (int i=0;i<n;i++){
			scanf("%d",&x);
			if (x&1)ans*=x;
		}
		printf("%d\n",ans);
		
	}
	return 0;
} 
