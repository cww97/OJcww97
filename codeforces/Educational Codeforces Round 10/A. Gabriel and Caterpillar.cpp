#include<cstdio>
#include<iostream>
using namespace std;
int h1,h2,a,b;

int judge2(){
	h1+=8*a;
	if (h1>=h2)return 0;
	for (int i=1;i<=100000;i++){
		h1+=12*(a-b);
		if (h1>=h2)return i;
	}
	return -1;
}

int main(){
	//freopen("fuck.in","r",stdin);
	while (scanf("%d%d%d%d",&h1,&h2,&a,&b)==4){
			printf("%d\n",judge2());
	}
	return 0;
} 
