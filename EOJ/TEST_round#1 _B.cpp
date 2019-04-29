/*
 * 就很骚
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
const int N = 1e5 + 7;
struct toy{
	char name[11];
	int di;
}toys[N];
int n, m;

int pow(int a, int x){
	if (x == 0) return 1;
	return -1;
}

int main(){
	//freopen("in.txt", "r", stdin);
	for (;~scanf("%d%d",&n, &m);){
		for (int i = 0; i<n; i++){
			scanf("%d %s\n", &toys[i].di, toys[i].name);
		}
		int di, step;
		int ans = 0;
		for (;m--;){
			scanf("%d%d", &di, &step);
			ans = (ans + step * pow(-1, toys[ans].di ^ di ^ 1) + n) % n;
			//printf("ans = %d\n", ans);
		}
		
		printf("%s\n", toys[ans].name);
	}
	return 0;
}