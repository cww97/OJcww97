#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1100;
struct point{
	int x,y,col;double rad;
	point(int x=0,int y=0):x(x),y(y){}
	bool  operator < (const point &a)const
	    {return rad<a.rad;}
	bool  operator ^ (const point &a)const
	    {return x*a.y-y*a.x>=0;}
	point operator - (const point &a)const
        {return point(x-a.x,y-a.y);}
}a[N],p[N],zero;
int n,L,R,cnt;
int main(){
	freopen("fuck.in","r",stdin);
	zero.x=zero.y=0;
	for (;~scanf("%d",&n)&&n;){
		for (int i=0;i<n;i++)
		  scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].col);
		int ans=0;
		for (int i=0;i<n;i++){
			int P=0;
			
			for (int j=0;j<n;j++){
				if (i==j)continue;
				p[P]=a[j]-a[i];
				if (a[j].col)p[P]=zero-p[P];
				p[P].rad=atan2(p[P].y,p[P].x);
				P++;
			}
			sort(p,p+P);
			for (int j=0;j<P;j++)
			//printf("x=%d y=%d rad=%.2lf\n",p[j].x,p[j].y,p[j].rad); 
		    L=0;R=0;cnt=2;
		    for (;L<P;){
			    if (L==R){R=(R+1)%P;cnt++;}
			    while(L!=R&&p[L]^p[R]){R=(R+1)%P;cnt++;}
			    L++; cnt--; ans=max(ans,cnt);
			    //printf("L=%d R=%d ans=%d\n",L-1,R,ans);
		    }
		    //printf("base=%d ans=%d\n",i,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
