#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 111;

int n;
int g[N][N], f[2][26][N][N];// 01 k i j

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &g[i][j]);
		}
	}

	memset(f, INF, sizeof f);
	//	cout<<f[0][0][0][0]<<endl;
	f[0][0][1][1] = f[1][0][1][1] = g[1][1];
	for (int i = 2; i <= n; i++) {
		f[0][0][1][i] = f[0][0][1][i - 1] + g[1][i];
	}
	for (int j = 2; j <= n; j++) {
		f[1][0][j][1] = f[1][0][j - 1][1] + g[j][1];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			f[0][0][i][j] = f[0][0][i][j - 1] + g[i][j];
			f[1][0][i][j] = f[1][0][i - 1][j] + g[i][j];
			for (int k = 1; k <= 25; k++) {
				f[0][k][i][j] = min(f[0][k][i][j - 1] , f[1][k - 1][i][j - 1] + (1 << (k-1))) + g[i][j] ;
				f[1][k][i][j] = min(f[1][k][i - 1][j] , f[0][k - 1][i - 1][j] + (1 << (k-1))) + g[i][j];
			}
		}
	}
	int ans = INT_MAX;
	for (int k = 0; k <= 25; k++)
		ans = min(ans, min(f[0][k][n][n], f[1][k][n][n]));
	printf("%d\n", ans);
	return 0;
}
