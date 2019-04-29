#include<cstdio>
#include<iostream>
using namespace std;
const int BASE=1000;

int power(int x,int y){
	if (!y)return 1;
	//if (y==1)return x % BASE;
	int tmp=power(x,y>>1) %BASE;
	tmp=(tmp*tmp)%BASE;
	if (y&1) tmp=tmp*x %BASE;
	return tmp %BASE;
}

int main(){
	int a,b;
	while (scanf("%d%d",&a,&b)==2){
		if (!a&!b)break;
		printf("%d\n",power(a,b));
	}
	return 0;
} 
