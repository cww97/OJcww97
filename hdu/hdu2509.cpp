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
		if (!cnt)ans = !!(n&1);//���ʱ��n��=0�ˣ�ǰ��ѭ��Ӧ��for��i�������ܹ�����Ϊ�������� 
		if (ans)puts("Yes");
		else puts("No");
	}
	return 0;
}
