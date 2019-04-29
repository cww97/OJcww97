#include<cstdio>
#include<iostream>
#include<algorithm> 
using namespace std;
double a;
int main(){
	while (~scanf("%lf",&a)){
		if (a>=0)printf("%.2lf\n",a);
		else printf("%.2lf\n",-a);
	}
	return 0;
}
