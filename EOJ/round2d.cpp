#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 55;
typedef long long LL;
char st[N];
int f[N];

int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d",&T);
	for (int cas = 0; cas<T;cas++){
		printf("Case %d: ",cas);
		int n,m;
		scanf("%d%d",&n,&m);
		int a,b;
		for (;m--;) scanf("%d%d",&a,&b);
		if (n&1) puts("NO");
		else puts("YES");

	}
	return 0;
}