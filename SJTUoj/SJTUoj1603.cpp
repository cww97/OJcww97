//https://acm.sjtu.edu.cn/OnlineJudge/problem/1603
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6;
int a[N], f[N];
int n;

int main(){
	freopen("in.txt", "r", stdin);
	for (;~scanf("%d", &n);){
		for (int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		memset(f, 0, sizeof(f));
		for (int i=n; i>=1; i--){
			for (int j=i+1; j<=n; j++){
				if(a[j] < a[i]) {
					f[i] = f[j] + 1;
					break;
				}
			}
		}
		for (int i=1; i<n; i++){
			printf("%d ", f[i]);
		}
		printf("%d\n", f[n]);
	}
	return 0;
}