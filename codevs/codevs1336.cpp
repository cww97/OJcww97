#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,mid,a[100000];
int main(){
	freopen("fuck.in","r",stdin);
	scanf("%d",&n);
	while (n--){
		scanf("%d",&m);
		for(int i=0;i<m;i++)scanf("%d",&a[i]);
		sort(a,a+m);
		if (m&1)mid=a[m>>1];
		else mid=a[(m>>1)-1];
		int sum=0;
		for (int i=0;i<m;i++) sum+=abs(mid-a[i]);
		printf("%d %d\n",mid,sum);
	}
} 
