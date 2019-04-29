#include<cstdio>
#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
int a[1100];

int main(){
	int n;
	while(scanf("%d",&n)==1&&n){
		int Min=INF,place=0;
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if (a[i]<Min){
				Min=a[i];
				place=i;
			}
		}
		swap(a[0],a[place]);
		for(int i=0;i<n-1;i++)printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
	}
	return 0;
}
