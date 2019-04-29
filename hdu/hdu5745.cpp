#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int N=100007,M=31;
int n,m;
char st1[N],st2[5007];
int sum1[N][M],sum2[M];

bool ok(int start){
	if (start>n-m+1)return 0;
	for (int i=0;i<26;i++){
		if (sum1[start+m-1][i]-sum1[start-1][i]!=sum2[i])
			return 0;
	}
	
	for (int i=1;i<=m;i++){
		int pos=start+i-1;
		if (st1[pos]==st2[i])continue;
		if (i == m) return 0;
		if (st1[pos]==st2[i+1]&&st1[pos+1]==st2[i])i++;
		else return 0;
	}
	return 1;
}

int main(){
	//freopen("fuck.in","r",stdin);
	int T;scanf("%d\n",&T);
	while (T--){
		scanf("%d%d\n",&n,&m);//Init
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		
		for (int i=1;i<=n;i++){
			scanf("%c",&st1[i]);
			for(int j=0;j<26;j++)
				sum1[i][j]=sum1[i-1][j];
			sum1[i][st1[i]-'a']++;
		}
		getchar();
		
		for (int i=1;i<=m;i++){
			scanf("%c",&st2[i]);
			sum2[st2[i]-'a']++;
		}
		getchar();          //endInit
		
		for (int i=1;i<=n;i++)
			putchar((ok(i))?'1':'0');
		puts("");
	}
	return 0;
}
