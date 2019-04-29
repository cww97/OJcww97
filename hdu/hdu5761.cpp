#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int a,v1,v2;
	while (scanf("%d%d%d",&a,&v1,&v2)==3){
		if(!a)puts("0.0000000000");
		else if (v1<=v2)puts("Infinity");
		else {
			double ans=a*v1*1.0/(v1*v1-v2*v2);
			printf("%.10lf\n",ans);
		}
	}
	return 0;
} 
