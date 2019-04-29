#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N = 1e7 + 7;
struct node{
	int index, al, ar, bl, br;
	node(){}
	node(int in, int x, int y, int z, int w):index(in),al(x),ar(y),bl(z),br(w){}
	bool operator <(const node& b)const{return index < b.index;}
}nodes[N];
LL n, m;

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%lld%lld", &n, &m);
	LL l, r, top = 0;
	memset(nodes, 0, sizeof(nodes));
	
	for (LL i = 1; i <= n; i++){
		scanf("%lld%lld", &l, &r);
		nodes[++top] = node(l,1,0,0,0);
		nodes[++top] = node(r,0,1,0,0);
	}
	for (LL i = 1; i <= m; i++){
		scanf("%lld%lld", &l, &r);
		nodes[++top] = node(l,0,0,1,0);
		nodes[++top] = node(r,0,0,0,1);
	}
	
	sort(nodes + 1, nodes + top +1 );
	LL cntA = 0, cntB = 0, ans = 0;
	
	for (LL i = 1; i < top; i++){
		node t = nodes[i];
		cntA += t.al - t.ar;
		cntB += t.bl - t.br;
		//printf("%lld %lld\n", cntA, cntB);
		if (cntA > 0 && cntB == 0){
			ans += nodes[i+1].index - t.index;
		}
	}
	printf("%lld\n", ans);
	return 0;
}