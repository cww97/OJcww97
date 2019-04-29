#include<cmath>
#include<cstdio>
using namespace std;
double a,b,c,d;
int main(){
	while (scanf("%lf%lf%lf%lf",&a,&b,&c,&d)==4){
		a=(a-c)*(a-c);
		b=(b-d)*(b-d);
		a=sqrt(a+b);
		printf("%.2lf\n",a);
	}
	return 0;
} 
