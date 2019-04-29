#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream> 
using namespace std;
const int INF=999999999;
const int N=400;
struct Edge{
	int from,to,cap,flow;
	Edge(int x,int y,int z,int w):from(x),to(y),cap(z),flow(w){}
};
int n,m,s,t;
vector<Edge>edges;
vector<int>G[N];
bool vis[N];
int d[N],cur[N];

void AddEdge(int from,int to,int cap){
	edges.push_back(Edge(from,to,cap,0));
	edges.push_back(Edge(to,from, 0 ,0));
	int top=edges.size();
	G[from].push_back(top-2);
	G[ to ].push_back(top-1);
}

bool BFS(){
	memset(vis,0,sizeof(vis));
	queue<int>Q;
	Q.push(s);d[s]=0;vis[s]=1;
	while (!Q.empty()){
		int x=Q.front();Q.pop();
		for (int i=0;i<G[x].size();i++){
			Edge& e=edges[G[x][i]];
			if (vis[e.to]||e.cap<=e.flow)continue;
			vis[e.to]=1; d[e.to]=d[x]+1;
			Q.push(e.to);
		}
	}
	return vis[t];
}

int DFS(int x,int a){
	if (x==t||a==0)return a;
	int flow=0,f;
	for (int& i=cur[x];i<G[x].size();i++){
		Edge &e=edges[G[x][i]];
		if (d[x]+1!=d[e.to]||
		    (f=DFS(e.to,min(a,e.cap-e.flow)))<=0)continue;
		e.flow+=f;
		edges[G[x][i]^1].flow-=f;
		flow+=f; a-=f;
		if (a==0)break;
	}
	return flow;
}

int Maxflow(int s,int t){
	int flow=0;
	while (BFS()){
		memset(cur,0,sizeof(cur));
		int f=DFS(s,INF);
		flow+=f;
	}
	return flow;
}

int main(){
	//freopen("fuck.in","r",stdin);
	for (;scanf("%d%d",&m,&n)==2;){
		s=1;t=n;
		edges.clear();
		for (int i=0;i<=n;i++)G[i].clear();
		for (int i=0;i<m;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			AddEdge(x,y,z);
		}
		printf("%d\n",Maxflow(1,4));
	}
}
