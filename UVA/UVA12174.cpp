#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=2001000;
int i,j,n,s,vis[N],a[N],ans,cnt;
bool ok[N];

bool check(int x){
	for (j=x;j<=n+s;j+=s)
	  if (!ok[j])return 0;
	return 1;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d",&T);
	for (;T--;){
		scanf("%d%d",&s,&n);
		memset(a,-1,sizeof(a));
		memset(ok,0,sizeof(ok));
		memset(vis,0,sizeof(vis));
		for (i=1;i<=n;i++)scanf("%d",&a[s+i]);
		cnt=0;
		for (i=1;i<=n+s;i++){       //iÎªÆðµã
		    if (cnt==s) ok[i]=1;
		    if (i<=s&&cnt==i-1)ok[i]=1;//left
		    if (i>n+1&&cnt==n+s-i+1)ok[i]=1;//right
		    if (a[i]!=-1&&--vis[a[i]]==0)cnt--;
		    if (a[s+i]!=-1&&vis[a[s+i]]++==0)cnt++;
		}
		ans=0;                 //begin
		for (i=1;i<=s;i++) if(check(i))ans++;
		if (ans==n+1)ans=s;
		printf("%d\n",ans);
	}
	return 0;
}
