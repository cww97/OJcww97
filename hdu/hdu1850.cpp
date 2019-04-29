#include<cstdio>
using namespace std;
const int N=111;
int a[N];
int main(){
	int n;
	while (~scanf("%d",&n)&&n){
		int nim=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			nim ^= a[i];
		}
		if (!nim)puts("0");
		else {
			int cnt=0;
			for (int i=1;i<=n;i++){
				int kk = nim^a[i];
				if (a[i]>kk)cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
} 
