#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N = 1e7 + 7;

struct node{
	int al, ar, bl, br;
	node(){}
	node(int x, int y, int z, int w):al(x),ar(y),bl(z),br(w){}
	node add(node b){return node(al+b.al, ar+b.ar, bl+b.bl, br+b.br);}
}nodes[N];

LL n, m, a[N];
map <LL,LL> mp;

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%lld%lld", &n, &m);
	LL l, r, top = 0;
	memset(nodes, 0, sizeof(nodes));
	
	for (LL i = 1; i <= n; i++){
		scanf("%lld%lld", &l, &r);
		if (!mp[l]) mp[l] = ++top;
		nodes[mp[l]] = nodes[mp[l]].add(node(1,0,0,0));
		if (!mp[r]) mp[r] = ++top;
		nodes[mp[r]] = nodes[mp[r]].add(node(0,1,0,0));
		a[i*2 - 1] = l;
		a[i*2] = r;
	}
	for (LL i = 1; i <= m; i++){
		scanf("%lld%lld", &l, &r);
		if (!mp[l]) mp[l] = ++top;
		nodes[mp[l]] = nodes[mp[l]].add(node(0,0,1,0));
		if (!mp[r]) mp[r] = ++top;
		nodes[mp[r]] = nodes[mp[r]].add(node(0,0,0,1));
		a[n*2 + i*2 - 1] = l;
		a[n*2 + i*2] = r;
	}
	
	sort(a + 1, a + 2*n+2*m+1 );
	// top == cnt
	LL cnt = unique(a+1, a+n*2+m*2+1) - (a+1);
	LL cntA = 0, cntB = 0, ans = 0;
	
	for (LL i = 1; i < cnt; i++){
		node t = nodes[mp[a[i]]];
		cntA += t.al - t.ar;
		cntB += t.bl - t.br;
		//printf("%lld %lld\n", cntA, cntB);
		if (cntA > 0 && cntB == 0){
			ans += a[i+1] - a[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}