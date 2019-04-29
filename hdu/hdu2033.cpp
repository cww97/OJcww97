#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int T;scanf("%d",&T);
	int ah,am,as,bh,bm,bs;
	while (T--){
		scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
		int t=as+bs;
		as=t%60;
		t/=60;
		t+=am+bm;
		am=t%60;
		t/=60;
		ah+=bh+t;
		printf("%d %d %d\n",ah,am,as);
	}
	return 0;
} 
