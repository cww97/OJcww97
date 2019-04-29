#include<cstdio>
#include<iostream>
using namespace std;
int x,y,A,a[50];

int check(int x){
	int s=0,xx=x;
	while (x){
		s+=(x%10)*(x%10)*(x%10);
		x/=10;
	}
	return s==xx;
}

int main(){
	while (scanf("%d%d",&x,&y)==2){
		if (x>y){int t=x;x=y;y=x;}
		A=0;
		for (int i=x;i<=y;i++){
			if (check(i))a[++A]=i;
		}
		if (!A)puts("no");
		else {
			for (int i=1;i<A;i++)printf("%d ",a[i]);
			printf("%d\n",a[A]);
		}
	}
	return 0;
} 
