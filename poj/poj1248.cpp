#include<cstdio>
#include<algorithm>
#include<cstring>  
using namespace std;
int v,w,x,y,z,n,ta;
char st[20];

void solve(){
	for (v=n;v>=1;v--)
	  for (w=n;w>=1;w--)
		for (x=n;x>=1;x--)
		  for (y=n;y>=1;y--)
		    for (z=n;z>=1;z--){
		        if (v==w||v==x||v==y||v==z||w==x
				  ||w==y||w==z||x==y||x==z||y==z)continue;
				if (((st[v]-64)-(st[w]-64)*(st[w]-64)
				    +(st[x]-64)*(st[x]-64)*(st[x]-64)
				    -(st[y]-64)*(st[y]-64)*(st[y]-64)*(st[y]-64)
				    +(st[z]-64)*(st[z]-64)*(st[z]-64)*(st[z]-64)*(st[z]-64))==ta){
				    printf("%c%c%c%c%c\n",st[v],st[w],st[x],st[y],st[z]);
				    return ;
				}
		    }
	printf("no solution\n");
}

int main(){
	while(scanf("%d%s",&ta,st+1),ta){
		n=strlen(st+1);
		sort(st+1,st+n+1);
        solve();
	}
	return 0;
}
