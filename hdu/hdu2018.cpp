#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int f[60],n;
	for (int i=1;i<=4;i++)f[i]=i;
	for (int i=5;i<60;i++)f[i]=f[i-1]+f[i-3];
	while (~scanf("%d",&n)&&n)printf("%d\n",f[n]);
	return 0;
}
