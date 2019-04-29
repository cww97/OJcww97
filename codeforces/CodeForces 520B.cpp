#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=23333;
struct node{
	int x,s;
	node(int x=0,int s=0):x(x),s(s){};
};
int i,n,k;
bool vis[N];
queue<node>q;
int main(){
  //freopen("fuck.in","r",stdin);
  for (;scanf("%d%d",&n,&k)==2;){
	if (n>=k)printf("%d\n",n-k);
	else{
	  memset(vis,0,sizeof(vis));
	  while (!q.empty())q.pop();
	  vis[n]=1;
	  for (q.push(node(n,0));!q.empty();q.pop()){
		node t=q.front();
		if (t.x==k)break;
		if (t.x-1>=0&&!vis[t.x-1]){
		  vis[t.x-1]=1;
		  q.push(node(t.x-1,t.s+1));
		}
		if (t.x  <=k&&!vis[t.x*2]){
			vis[t.x*2]=1;
			q.push(node(t.x*2,t.s+1));
		}
	  }
	  printf("%d\n",q.front().s);
	}
  }
  return 0;
}
