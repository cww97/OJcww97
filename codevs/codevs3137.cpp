#include<cstdio>
#include<stack>
using namespace std;
int n,x,ask;
int main (){
	scanf("%d",&n);
	stack<int>s;
	for (;n--;){
		scanf("%d",&ask);
		if (ask==2)s.pop();
		else {
			scanf("%d",&x);
			s.push(x);
		}
	}
	if (s.empty())puts("impossible!");
	else printf("%d\n",s.top()); 
	return 0;
}
