#include<cstdio>
#include<iostream>
int i,x,ans;
using namespace std;
int main(){
	while (~scanf("%d",&x)){	
	ans=x/5;
	if (x%5!=0)ans++;
	printf("%d\n",ans);
	}
	return 0;
} 
