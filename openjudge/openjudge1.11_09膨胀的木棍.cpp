/*
 * OpenJudge 1.11_09膨胀的木棍
 * Author: cww97
 */
#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
const int INF = 0x3f3f3f3f;
const double EPS = 1e-15;

double get_arc(double mid, double l){
    double r = l / sin(mid);
    // 弧长公式 l = r/PI * PI*mid = r * mid
    return 2 * r * mid;
}

int main(){
    //freopen("in.txt", "r", stdin);
    double L, n, C;
	cin >> L >> n >> C;
	if(L*n*C == 0) cout << "0.000" << endl;
    else{
        double arc = (1 + n * C) * L;
        L /= 2.0;
        double l = 0, r = PI/2.0, mid;
        for (;r-l > EPS;){ // 二分圆心角
            mid = (l+r) / 2.0;
            if (get_arc(mid, L) > arc) r = mid;
            else l = mid;
        }
        double ans = L/sin(mid) * (1-cos(mid));
        printf("%.3f\n", ans);
    }
	return 0;
}
