#include<string>
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int n;scanf("%d",&n);
	string st;
	while (n--){
		cin>>st;
		int len=st.size();
		int num=0;
		for (int i=0;i<len;i++){
			if(st[i]>='0'&&st[i]<='9')num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
