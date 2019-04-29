#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n,x;scanf("%d",&n);
	while (n--){
		scanf("%*6d%d",&x);
		printf("6%05d\n",x);
	}	
	return 0;
} 
