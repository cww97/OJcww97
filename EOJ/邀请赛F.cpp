#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2333;

struct line
{
	int l, r, num;
	void read(){
		scanf("%d%d%d", &l, &r, &num);
	}
	bool operator < (const line& b)const{
		return r < b.r;
	}
}lines[N];

bool fix[N];
int sum(int l, int r){
	int ans = 0;
	for (int i = l; i<=r; i++){
		ans += fix[i];
	}
	return ans;
}

int n, m, k;

int main(){
	//freopen("in.txt", "r", stdin);
	int T, x;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		printf("Case %d: ", cas);
		scanf("%d%d%d", &n, &m, &k);
		memset(fix, 0, sizeof(fix));
		for (int i = 1; i <= k; i++){
			scanf("%d", &x);
			fix[x] = 1;
		}
		for (int i = 0; i < m; i++){
			lines[i].read();
		}
		sort(lines, lines + m);

		int ans = 0;
		bool ok = true;
		for (int i = 0; i < m; i++){
			//printf("line %d : [%d,%d]ned %d\n", i, lines[i].l, lines[i].r, lines[i].num);
			if (lines[i].r - lines[i].l + 1 < lines[i].num){
				ok = false; break;
			}
			int ned = lines[i].num - sum(lines[i].l, lines[i].r);
			//printf ("ned = %d\n", ned);
			if (ned <= 0) continue;
			for (int j = lines[i].r; j>=lines[i].l;j--){
				if (!fix[j]) fix[j] = 1, ans++, ned--;
				if (ned == 0) break;
			}
		}
		if (ok)printf("%d\n", ans);
		else puts("-1");
	}
	return 0;
}