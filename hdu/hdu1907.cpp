#include<cstdio>
using namespace std;
int main(){
	int T,n,x;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int ans=0,cnt=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			ans ^= x;
			if (x>1)cnt++;
		}
		if (!cnt)ans = !(n&1);
		if (ans)puts("John");
		else puts("Brother");
	}
	return 0;
} 
