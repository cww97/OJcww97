#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10007;
int a[N];
int main(){
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=0,mid=a[(n+1)>>1];
		for (int i=1;i<=n;i++){
			ans+=abs(a[i]-mid);
		}
		printf("%d\n",ans);
	}
	return 0;
} 
