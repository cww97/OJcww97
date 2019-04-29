#include<cstdio>
#include<cstring>
using namespace std;
const int N=200007,P=10007;
int n;
char a[N];
int f[N],next[N];

void getNext(){
	int i=0,j=-1;
	next[0]=-1;
	while (i<n){
		if (j==-1||a[i]==a[j]){
			//if (a[++i]!=a[++j])next[i]=j;
			//else next[i]=next[j];
			next[++i]=++j;
			//printf("next[%d]=%d\n",i,next[i]);
		}else j=next[j];
	}
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d\n",&n);
		for (int i=0;i<n;i++)scanf("%c",&a[i]);
		getNext();
		int ans=0;
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++){
			//if (next[i]<=0)f[i]=1;
			//else 
				f[i]=(f[next[i]]+1)%P;
			//printf("f[%d]=%d\n",i,f[i]);
			ans=(ans+f[i])%P;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
