#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N = 1e5 + 5;
const LL MOD = 9901;
//素数
LL p[N], P = 0;
bool isPrime[N];

void getPrime(){
	P = 0;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = false;
	for (int i = 2; i < N; i++){
		if (isPrime[i]) p[P++] = i;
		for (int j = 0; j<P && i*p[j]<N; j++){
			isPrime[i * p[j]] = false;
			if (i % p[j] == 0) break;
		}
	}
}

LL mul(LL a, LL b, LL M){
	LL ans = 0;
	for (;b;b >>= 1,a = (a + a) % M){
		if (b&1) ans = (ans + a) % M;
	}
	return ans % M;
}

LL power(LL a,LL x,LL M){
	if (x == 0) return 1;
	LL ans = 1, tmp = a;
	for (;x;x>>=1,tmp = mul(tmp, tmp, M)){
		if (x&1) ans = mul(ans, tmp, M);
	}
	return ans % M;
}

LL work(LL a, LL b){
	LL ans = 1;
	for (int i = 0; i < P; i++)if (a%p[i] == 0){
		int num = 0;
		for (;a%p[i] == 0;){
			num++;
			a /= p[i];
		}
		LL M = (p[i] - 1) * MOD;
		LL tmp = power(p[i], num * b + 1, M) - 1 + M;
		ans *= tmp/(p[i] - 1);
		ans %= MOD;
	}
	if (a>1){//还剩个大素数
		LL M = (a - 1) * MOD;
		LL tmp = power(a, b + 1, M) - 1 + M;
		ans *= tmp/(a - 1);
		ans %= MOD;
	}
	return ans % MOD;
}

int main(){
	//freopen("in.txt", "r", stdin);
	getPrime();
	LL a, b;
	for (; ~scanf("%lld%lld", &a, &b);){
		printf("%lld\n",  work(a, b));
	}

	return 0;
}
