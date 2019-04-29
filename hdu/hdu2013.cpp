#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	while (scanf("%d",&n)==1){
		int x=1;
		for (int i=1;i<n;i++){
			x=x+1<<1;
		}
		printf("%d\n",x); 
		
	}
	return 0;
} 
