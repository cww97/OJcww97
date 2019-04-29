#include<cstdio>
#include<iostream>
using namespace std;
int x,y,ans0,ans1;
int main(){
	while(scanf("%d%d",&x,&y)==2){
		ans0=ans1=0;
		if (x>y){int t=x;x=y;y=t;}
		for (int i=x;i<=y;i++){
			if (i&1) ans1+=i*i*i;
			else ans0+=i*i;
		}
		printf("%d %d\n",ans0,ans1);
	} 
	return 0;
} 
