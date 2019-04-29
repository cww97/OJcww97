#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int x1,x2,x3,y1,y2,y3,ans=0;
int main(){
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	if ((x1==x2&&x1==x3)||(y1==y2&&y1==x3)) ans=1;
	else {
		if (x1==x2&&x1!=x3&&!(min(y1,y2)<y3&&y3<max(y1,y2)))ans=2;
		if (x1==x3&&x1!=x2&&!(min(y1,y3)<y2&&y2<max(y1,y3)))ans=2;
		if (x2==x3&&x1!=x2&&!(min(y2,y3)<y1&&y1<max(y2,y3)))ans=2;
		if (y1==y2&&y1!=y3&&!(min(x1,x2)<x3&&x3<max(x1,x2)))ans=2;
		if (y1==y3&&y1!=y2&&!(min(x1,x3)<x2&&x2<max(x1,x3)))ans=2;
		if (y2==y3&&y1!=y2&&!(min(x2,x3)<x1&&x1<max(x2,x3)))ans=2;
	}
	if (ans==0)ans=3;
	printf("%d\n",ans);
	return 0;
} 
