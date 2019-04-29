#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const int N=2333;
struct Edge{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
int s,t,n,m,top;
vector<Edge>edges;//0=s,1~n人，n+1~n+m组，n+m+1=t
vector<int>G[N];//邻接表
vector<int>group[N];//记录每个人属于集合
bool vis[N];//use when bfs
int d[N],cur[N];//dist,now edge

void AddEdge(int from,int to,int cap){
	edges.push_back(Edge(from,to,cap,0));
	edges.push_back(Edge(to,from, 0 ,0));
	top=edges.size();
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
			Edge &e=edges[G[x][i]];
			if (vis[e.to]||e.cap<=e.flow)continue;
			vis[e.to]=1;
			d[e.to]=d[x]+1;
			Q.push(e.to);
		}
	}
	return vis[t];
}

int DFS(int x,int a){
	if (x==t||a==0)return a;
	int flow = 0,f;
	for (int& i=cur[x];i<G[x].size();i++){
		Edge& e=edges[G[x][i]];
		if (d[x]+1!=d[e.to])continue;
		if ((f=DFS(e.to,min(a,e.cap-e.flow)))<=0)continue;
		e.flow+=f;
		edges[G[x][i]^1].flow-=f;
		flow+=f; a-=f;
		if (a==0)break;
	}
	return flow;
}

int Maxflow(int s,int t,int x){
	int flow=0;
	while(BFS()){
		memset(cur,0,sizeof(cur));
		flow+=DFS(s,x);
	}
	return flow;
}

bool check(int x){
	edges.clear();                          //init
	for (int i=0;i<=n+m+1;i++)G[i].clear();
	for (int i=n+1;i<=n+m;i++)AddEdge(i,t,x);
	for (int i=1;i<=n;i++){
		AddEdge(s,i,1);
		for (int j=0;j<group[i].size();j++){
			AddEdge(i,group[i][j],1);
		}
	}
	
	int flow=Maxflow(s,t,x);                 //run
	for (int i=0;i<G[s].size();i++){
		if (edges[G[s][i]].flow!=1)return 0;
	}
	return 1;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int k;
	char ch;
	for (;scanf("%d%d",&n,&m)==2&&(n+m);){
		s=0;t=m+n+1;                             //read
		for (int i=1;i<=n;i++){
			string st;cin>>st;
			group[i].clear();
			while (~scanf("%c",&ch)&&ch!='\n'){
				scanf("%d",&k);
				group[i].push_back(n+k+1);
			}
		}
	    
		int L=0,R=n;                             //erfen
		while (L<R){
			if (L==R)break;
			int mid=(L+R)>>1;
			bool ok=check(mid);
			if (ok) R=mid;
			else L=mid+1;
		}
		printf("%d\n",L);
	}
}
