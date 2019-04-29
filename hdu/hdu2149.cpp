#include<cstdio>
using namespace std;
int main(){
	int n,m;
	while (scanf("%d%d",&m,&n)==2){
		if (n>=m){
			for (int i=m;i<n;i++)printf("%d ",i);
			printf("%d\n",n);
		}else {
			int x=m%(n+1);
			if (x)printf("%d\n",x);
			else puts("none");
		}
	}
	return 0;
} 
