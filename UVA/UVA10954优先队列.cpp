#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int i,n,x;

int main(){
	//freopen("fuck.in","r",stdin);
	for(;scanf("%d",&n)==1&&n;){
		priority_queue<int,vector<int>, greater<int> >q;
		for (int i=1;i<=n;i++){scanf("%d",&x);q.push(x);}
		int ans=0;
		for (int i=1;i<n;i++){
			int x=q.top();q.pop();
			int y=q.top();q.pop();
			ans+=x+y;
			q.push(x+y);
		}
		printf("%d\n",ans);
	}
	return 0;
}

