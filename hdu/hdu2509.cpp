#include<cstdio>
#include<iostream>
using namespace std; 

int main(){
	int n,x;
	while (scanf("%d",&n)==1){
		int ans=0,cnt=0;
		for (;n--;){
			scanf("%d",&x);
			ans ^= x;
			if (x>1) cnt++;
		}
		if (!cnt)ans = !!(n&1);//这个时候n都=0了，前面循环应该for个i，这里能过是因为数据弱吧 
		if (ans)puts("Yes");
		else puts("No");
	}
	return 0;
}
