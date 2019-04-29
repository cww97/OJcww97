#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;
typedef pair<int,int>pa;
const int N=1100;
int n,m,g[N][N],ans[N*2];
int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	for(;T--;){
		scanf("%d%d\n",&n,&m);
		memset(g,0,sizeof(g));
		memset(ans,0,sizeof(ans));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				char ch;scanf("%c",&ch);
				if (ch=='.')g[i][j]=g[i-1][j]+1;
			}
			scanf("\n");
		}
		for (int i=1;i<=n;i++){
			stack<pa>s;
			for (int j=1;j<=m;j++){
				int t=j;
				while (!s.empty()&&s.top().first>=g[i][j]){
					t=s.top().second;s.pop();
				}
				if (!g[i][j])continue;
				if (s.empty()||g[i][j]-s.top().first>t-s.top().second){
					ans[g[i][j]+j-t+1]++;
					s.push(pa(g[i][j],t)); 
				}else ans[s.top().first+j-s.top().second+1]++;
			}
		}
		for (int i=1;i<=n+m;i++){
			if (ans[i])printf("%d x %d\n",ans[i],i*2);
		}	
	}
	return 0;
} 
