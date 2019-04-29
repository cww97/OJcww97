#include<cstdio>
#include<iostream>
using namespace std;
int ans0,ans1,ans2,n;
double x;
int main(){
	for (;scanf("%d",&n)==1&&n;){
		ans0=ans1=ans2=0;
		for (int i=0;i<n;i++){
			scanf("%lf",&x);
			if (x>0)ans1++;
			else if (x<0)ans2++;
			else ans0++;
		}
		printf("%d %d %d\n",ans2,ans0,ans1);
		
	}
	return 0;
}
