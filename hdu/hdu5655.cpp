#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[5];
bool check(){
	if (a[0]+a[1]<0)return 1;//longlong加爆的情况 
	if (a[0]+a[2]<0)return 1;
	if (a[1]+a[2]<0)return 1;
	if (a[0]+a[1]+a[2]<0)return 1;
	return (a[0]+a[1]+a[2]>a[3])&&(a[0]);//注意0的情况 
} 

int main(){
	int T;scanf("%d",&T);
	while (T--){
		for (int i=0;i<4;i++)cin>>a[i];
		sort(a,a+4);
		if (check())puts("Yes");
		else puts("No");
	}
	return 0;
} 
