#include<cstdio>
#include<cstring>
using namespace std;
const int N=(1<<21)+7;
int sg[N];
int c[23],C;//the position of chesses

int next(int x){//move the x-th chess 
	for (int i=x;i<=C;i++){
		if (c[i+1]>c[i]+1)return 1<<(c[i]+1);
	}
	return 0;
}

void getSG(){
	bool vis[107];// enough??
	for (int i=N-9;i>=0;i-=2){//downto
		C=0;           //get the stituation
		for (int j=1;j<=20;j++)//num->array
			if (i&(1<<j)) c[++C]=j;
		c[C+1]=21;
		memset(vis,0,sizeof(vis));//sgsgsg
		for (int j=1;j<=C;j++){
			int nxt=next(j);//move a chess
			if (nxt)vis[sg[i^(1<<c[j])^nxt]]=1;//- +
		}
		for (int j=0;j<107;j++)
			if(!vis[j]){sg[i]=j;break;}
	}
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T,n,m,x;
	getSG();
	scanf("%d",&T);
	while (T--){
		int ans = 0;
		scanf("%d",&n);
		for (;n--;){
			int che = 0;
			scanf("%d",&m);
			for (;m--;){
				scanf("%d",&x);
				che |= 1<<x;//+=
			}
			ans ^= sg[che];
		}
		if (ans)puts("YES");
		else puts("NO");
	}
	return 0;
}
