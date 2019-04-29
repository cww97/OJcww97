#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int ddx[]={-1,-1,1,1};
const int ddy[]={-1,1,-1,1};
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int cnt=0,dia=0,dib=0,k,l,ti,x,y;
int row[5],col[5],g[5][5];

void readln(){
	for (int i=1;i<=3;i++){
	  for (int j=1;j<=3;j++){
	  	scanf("%d",g[i][j]);
	  	if (!g[i][j]){
	  		a[++A]=node(i,j);
	  	}
	  	else {
	  		cnt++;
	  		v[g[i][j]]=1;
	  	}
	  }
	}
}

void writeln(){
	for (int i=1;i<=3;i++){
	  for (int j=1;j<3;j++)printf("%d ",g[i][j]);
	  printf("%d\n",g[i][3]);
	}
}

int main(){
	freopen("fuck.in","r",stdin);
	
	if (cnt<9)puts("Too Many");
	else writeln();
	return 0;
} 
