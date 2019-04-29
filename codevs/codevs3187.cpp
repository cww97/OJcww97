#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
int i,ask,x;
int main(){
	int N;scanf("%d",&N);
	queue <int> q;
	for(;N--;){
		scanf("%d",&ask);
		if (ask==1){scanf("%d",&x);q.push(x);}
		if (ask==2)q.pop();
		if (ask==3)printf("%d\n",q.front());
	}
	return 0;
} 
