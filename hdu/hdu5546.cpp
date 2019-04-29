#include<cstdio>
#include<cstring>
using namespace std;
const int dx[5]={0,0,0,1,-1};
const int dy[5]={0,-1,1,0,0};
int n,ti,i,j,g[11][11],sum;
bool v[11][11],vv[11][11];
char ch;

void dfs(int x,int y){
	v[x][y]=true;
	for (int i=1;i<=4;i++){
		int cx=x+dx[i];
		int cy=y+dy[i];
		if (g[cx][cy]<2) {
			if (!vv[cx][cy])sum+=g[cx][cy];	
			vv[cx][cy]=true;
		}
		    
		else if (!v[cx][cy])dfs(cx,cy);
	}
}

int main(){
	scanf("%d%c",&n,&ch);
	for (ti=1;ti<=n;ti++){
		memset(g,0,sizeof(g));
		scanf("%c",&ch);
		for (i=1;i<=9;i++){
			for (j=1;j<=9;j++){
				scanf("%c",&ch);
				if (ch=='.')g[i][j]=1;
				else if (ch=='x')g[i][j]=0;
				else g[i][j]=9;
			}
			scanf("%c",&ch);
		}
		
		bool ok=false;
		memset(v,0,sizeof(v));
		for (i=1;i<=9;i++){
			if (ok) break;
			for (j=1;j<=9;j++){
		  	    sum=0;
		  	    if ((!v[i][j])&&(g[i][j]==9)){
		  	    	memset(vv,0,sizeof(v));
			        dfs(i,j);
			        if (1==sum) {ok=true; break;}
			    }
		    }
		}
		  
		if (ok) printf("Case #%d: Can kill in one move!!!\n",ti);   
		else    printf("Case #%d: Can not kill in one move!!!\n",ti);
	}
	return 0;
}
