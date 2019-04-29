#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1100;
int n,m,x,y,arr[N],f[2][N];
char ch;
int main(){
	//freopen("fuck.in","r",stdin);
	for (;scanf("%d%d%d%d\n",&n,&m,&x,&y)==4;){
		memset(arr,0,sizeof(arr));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
		  	    scanf("%c",&ch);
		  	    if (ch=='#')arr[j]++;
		    }
		    scanf("\n");
		}
		memset(f,0x3f,sizeof(f));
		f[0][0]=0;f[1][0]=0;
	    for (int i=1;i<=m;i++) 
          for (int a=x;a<=y&&i-a>=0;a++){
		    int sum1=0,sum2=0; 
            for (int j=i-a+1;j<=i&&j>0;j++)
			    {sum1+=arr[j];sum2+=n-arr[j];}
			    f[0][i]=min(f[0][i],f[1][i-a]+sum1); 
                f[1][i]=min(f[1][i],f[0][i-a]+sum2);
		  }
		printf("%d\n",min(f[0][m],f[1][m]));
    }
	return 0;
}
