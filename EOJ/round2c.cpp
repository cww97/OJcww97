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
	for (;~scanf("%s\n",st);){
		int len = strlen(st), ans = 0;
		memset(f, 0, sizeof(f));
		for (int i=0; i<len; i++){
			for (int j=0; j<i; j++) if (st[j]<st[i]){
				f[i] = max(f[i], f[j]);
			}
			f[i]++;
			ans = max(ans, f[i]);
		}
		printf("%d\n",max(0, 26-ans));
	}
	return 0;
}