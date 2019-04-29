#include<cstdio>
using namespace std;
double x,a[301];
int i;
int main(){
	for (i=1;i<=300;i++)
	  a[i]=a[i-1]+1.0/(i+1);
	scanf("%lf",&x);
	while (x>0){
		for (i=1;i<=300;i++)
		  if (a[i]>=x)break;
		printf("%d card(s)\n",i);
		scanf("%lf",&x);
	}
	return 0;
} 
