#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double phi=(1+sqrt(5))/2.0;
int main(){
	int m,n;
	while (scanf("%d%d",&n,&m)==2){
		if (min(n,m)==(int)(phi*abs(n-m)))puts("0");
		else puts("1");
	}
	return 0;
} 
