#include<cstdio>
#include<cmath>
const double pi=3.14159265;
double x,y;
int N,n,ans;
int main (){
	scanf("%d",&N);
	for (n=1;n<=N;n++){
		scanf("%lf%lf",&x,&y);
		ans=(int)((pi*(x*x+y*y))/100.0)+1;
		printf("Property %d: This property will begin eroding in year %d.\n",n,ans);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
