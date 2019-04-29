#include<cstdio>
using namespace std;
double x,sum=0;
int i;
int main (){
	for(i=1;i<=12;i++){
		scanf("%lf",&x);
		sum+=x;
	}
	printf("$%.2f\n",sum/12.0);
	return 0;
} 
