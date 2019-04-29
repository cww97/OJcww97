//poj 3278
//by cww97
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1000000;
struct node{
	int x,s;//x=location,s=step
	node(int x=0,int s=0):x(x),s(s){};
};
int i,n,k;
bool vis[N];
queue<node>q;
int main(){
  //freopen("fuck.in","r",stdin);
  //freopen("fuck.out","w",stdout);
  for (;scanf("%d%d",&n,&k)==2;){
	if (n>=k)printf("%d\n",n-k);
	else{
	  memset(vis,0,sizeof(vis));
	  while (!q.empty())q.pop();
	  vis[n]=1;
	  for (q.push(node(n,0));!q.empty();q.pop()){
		node t=q.front();
		//printf("x=%d step=%d\n",t.x,t.s);
		if (t.x==k)break;
		if (t.x-1>=0&&!vis[t.x-1]){//left
		  vis[t.x-1]=1;
		  q.push(node(t.x-1,t.s+1));
		}
		if (t.x+1<=k&&!vis[t.x+1]){//right
		  vis[t.x+1]=1;
		  q.push(node(t.x+1,t.s+1));
		}
		if (t.x  <=k&&!vis[t.x*2]){//Teleport
			vis[t.x*2]=1;
			q.push(node(t.x*2,t.s+1));
		}
	  }
	  printf("%d\n",q.front().s);
	}
  }
  return 0;
}
