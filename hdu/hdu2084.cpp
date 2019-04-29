#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 107;
int a[N][N];

int main(){
	int T,n;
	scanf("%d",&T);
	while (T--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=i;j++){
				scanf("%d",&a[i][j]);
				a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
			}
		} 
		int ans=0;
		for (int i=1;i<=n;i++)ans=max(ans,a[n][i]);
		printf("%d\n",ans);
	}
	return 0;
} 
