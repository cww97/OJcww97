#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, m;
	for (;~scanf("%d%d", &n, &m);){
		int num = 0;
		for (int i=1; i<=n; i++){
			for (int j=1; j<m; j++){
				printf("%d ",++num);
			}
			printf ("%d\n", ++num);
		}
	}
	return 0;
}