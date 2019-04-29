#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int f[5010][5010]={},ans[5010]={};
int main()
{
	string s;
	int n,a[10]={},sum = 0;
	cin >> s;
	n = s.length();
	for (int i = 0;i < n;i++){
		for (int j = 0;j < n;j++){
			if (i - j < 0 || i+j >= n) break;
			if (s[i-j] != s[i+j]) break;
			f[i-j+1][i+j+1]=f[i-j+1][i] + 1;
		}
		for (int j = 0;j < n;j++){
			if (i - j < 0 || i + j + 1>= n) break;
			if (s[i-j] != s[i+j+1]) break;
			f[i-j+1][i+j+2]=f[i-j+1][i+1] + 1;
		}
	}
	for (int i = 1;i <=n;i++)
		for (int j=i;j<=n;j++) ans[f[i][j]]++;
	for (int i=n-1;i>=1;i--) ans[i]+=ans[i+1];
	for (int i=1;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << ans[n] << endl;
    return 0;
}
