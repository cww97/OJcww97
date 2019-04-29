#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1007;
int sg[N],fib[N];

void getFib(){
	fib[1] = 1 , fib[2] = 2;
	for (int i=3;i<=17;i++)
		fib[i]=fib[i-1]+fib[i-2];
}

void getSG(){
	getFib();
	/*memset(sg,0,sizeof(sg));
	int lastP;
	for (int i = 0; i < N ; i++ ){
		if (sg[i]==-1) sg[i] = i-lastP;
		else {//sg[i]==0
			lastP = i ;
			for (int j=1;j<17&&i+fib[j]<N;j++){
				sg[i+fib[j]] = -1 ;
			}
		}
		//printf("sg[%d]=%d\n",i,sg[i]);
	}*/
	int j;
	sg[0]=0;
	bool mex[17];
	for(int i=1;i<N;i++){
		memset(mex,0,sizeof(mex));
    	for (j=1 ;fib[j]<=i ;j++ )mex[sg[i-fib[j]]]=1;
    	for (j=0 ; j<N ; j++ )if(!mex[j])break;
    	sg[i] = j;
  	}
}
//by cww97
int main(){
	int x,y,z;
	getSG();
	while (scanf("%d%d%d",&x,&y,&z)==3){
		if ( !x&& !y&& !z ) break;
		int ans = sg[x]^sg[y]^sg[z];
		if (ans)puts("Fibo");
		else puts("Nacci");
	}
	return 0;
} 
