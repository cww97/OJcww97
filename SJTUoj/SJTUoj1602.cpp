#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6;
int m, n, a[N];

int main(){
	freopen("in.txt", "r", stdin);
	for (;~scanf("%d%d", &n, &m);){
		for (int i=0; i< m+n; i++)scanf("%d", &a[i]);
		sort(a, a+m+n);
		for (int i=0; i< m+n-1; i++)printf("%d ",a[i]);
		printf("%d\n", a[m+n-1]);
	}
	return 0;
}