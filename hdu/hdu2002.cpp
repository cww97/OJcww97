#include<cstdio>
#include<iostream>
#include<cmath>
#define PI 3.1415927
using namespace std;
double a;
int main(){
	while (~scanf("%lf",&a)){
		a=PI*(4.0/3)*a*a*a;
		printf("%.3lf\n",a);
	}
	return 0;
} 
