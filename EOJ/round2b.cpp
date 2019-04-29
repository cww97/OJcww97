#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a[40];

int main()
{
	//freopen("in.txt", "r", stdin);
	int T; 
	scanf("%d", &T);
	for (LL n;T--;)
	{
		scanf("%lld", &n);
		LL ansP = 1, ansQ = 1;
		int A = 0;
		for (; n; n >>= 1){
			a[++A] = n;
		}
		for (int i=A; i>1; i--){
			if (a[i] << 1 == a[i-1]) ansQ += ansP;
			else ansP += ansQ;
		}
		printf("%lld/%lld\n", ansP, ansQ);
	}
	return 0;
}