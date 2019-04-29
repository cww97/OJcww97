#include<cstdio>
using namespace std;
const int a[]={100,50,10,5,2,1};

int main(){
	int n,x;
	for (;scanf("%d",&n)&&n;){
		int ans=0;
		for (;n--;){
			scanf("%d",&x);
			//printf("x=%d\n",x);
			for (int i=0;i<6;i++)if (x>=a[i]&&x){
				int k = x / a[i];
				x-=k*a[i];
				ans+=k;
				//if (k) printf("a[%d]=%d,k=%d,ans=%d\n",i,a[i],k,ans);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
