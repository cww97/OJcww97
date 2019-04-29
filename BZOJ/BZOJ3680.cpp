#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e4 + 7;
const double eps = 1e-8;
int n;
double sqr(double x){return x*x;}

struct point
{
	double x, y, w;
	point(){}
	point (double _x, double _y):x(_x),y(_y){}
	inline void read(){
		scanf("%lf%lf%lf", &x, &y, &w);
	}
	double dist(double _x, double _y){
		return sqrt(sqr(x-_x) + sqr(y-_y));
	}
}po[N];

point climbHill(){
	double ansx = 0, ansy = 0;
	for (int i = 0; i < n; i++){
		ansx += po[i].x * po[i].w;
		ansy += po[i].y * po[i].w;
	}
	ansx /= n;
	ansy /= n;
	double t = 1000;
	for (;t > eps;){
		double x = 0, y = 0;
		for (int i = 0; i < n; i++){
			double dist = po[i].dist(ansx, ansy);
			x += (po[i].x - ansx) * po[i].w / dist;
			y += (po[i].y - ansy) * po[i].w / dist;
		}
		ansx += x * t;
		ansy += y * t;
		if (t > 0.5) t *= 0.5;
		else t *= 0.97;
		//printf("%.3f %.3f", ansx,ansy);
	}
	return point(ansx, ansy);
}


int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		po[i].read();
	}
	//puts("???");
	point ans = climbHill();
	printf("%.3f %.3f\n", ans.x, ans.y);
	return 0;
}