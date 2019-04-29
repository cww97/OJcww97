#include<cstdio>
#include<stack>
using namespace std;
int n,x,ask;
int main (){
	bool ok=1;
	scanf("%d",&n);
	stack<int>s;
	for (;n--;){
		scanf("%d",&ask);
		if (ask==2){
			if (s.empty()){ok=0;break;}
		    s.pop();	
		}
		else {
			scanf("%d",&x);
			s.push(x);
		}
	}
	if (s.empty()||!ok)puts("impossible!");
	else printf("%d\n",s.top()); 
	return 0;
}
