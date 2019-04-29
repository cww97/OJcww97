#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int i,x,ans,n,r1,r2;
bool watered[2020];
struct P{int x,y;}f1,f2,a[2020];
int dis(P xx,P yy){
	return ((xx.x-yy.x)*(xx.x-yy.x)
	       +(xx.y-yy.y)*(xx.y-yy.y));
}
bool cmp1(P x,P y){return (dis(x,f1)<dis(y,f1));}
bool cmp2(P x,P y){return (dis(x,f2)<dis(y,f2));}
void water(P fo,int r,int st){
	for (int i=st;i>=1;i--)
	  if (dis(fo,a[i])<=r) watered[i]=true;
}
int main(){
	while (~scanf("%d",&n)){	
	scanf("%d%d%d%d",&f1.x,&f1.y,&f2.x,&f2.y);
	for (int i=1;i<=n;i++) 
	    scanf("%d%d",&a[i].x,&a[i].y);

	sort(a+1,a+n+1,cmp1);
	memset(watered,0,sizeof(watered));
	r1=0;r2=0;
	for (int i=n;i>=1;i--){
		if (watered[i]) continue;
		if (dis(f1,a[i])>dis(f2,a[i]))
		    r2=max(r2,dis(f2,a[i]));
		else if (dis(f1,a[i])<dis(f2,a[i]))
		    r1=max(r1,dis(f1,a[i]));
		else if (dis(f1,a[i])==dis(f1,a[i-1]))
		    r1=max(r1,dis(f1,a[i]));
		else r2=max(r2,dis(f2,a[i]));
		water(f1,r1,i);
		water(f2,r2,i);
	}
	ans=r1+r2;//가가가가가가가 
	
	sort(a+1,a+n+1,cmp2);
	memset(watered,0,sizeof(watered));
	r1=0;r2=0;
	for (int i=n;i>=1;i--){
		if (watered[i]) continue;
		if (dis(f1,a[i])>dis(f2,a[i]))
		    r2=max(r2,dis(f2,a[i]));
		else if (dis(f1,a[i])<dis(f2,a[i]))
		    r1=max(r1,dis(f1,a[i]));
		else if (dis(f2,a[i])==dis(f2,a[i-1]))
		    r2=max(r2,dis(f2,a[i]));
		else r1=max(r1,dis(f1,a[i]));
		water(f1,r1,i);
		water(f2,r2,i);
	}
	ans=min(ans,r1+r2);//가가가가가 
	printf("%d\n",ans);
	}
	return 0;
} 
