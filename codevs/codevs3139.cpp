#include<cstdio>
#include<stack>
using namespace std;
int n,x,ask;
int main (){
	scanf("%d",&n);
	stack<int>s;
	for (;n--;){
		scanf("%d",&ask);
		if (ask==1){scanf("%d",&x);s.push(x);}
		if (ask==2){if (s.empty())continue;s.pop();}
		if (ask==3)printf("%d\n",s.top());
	}
	return 0;
}
