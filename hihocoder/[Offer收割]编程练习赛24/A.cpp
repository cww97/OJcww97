#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int h, m, s, t;

int main(){
    //freopen("in.txt", "r", stdin);
    int _;
    scanf("%d", &_);
    for (; _--;){
        scanf("%d%d%d%d", &h, &m, &s, &t);
        t += h * 3600 + m * 60 + s;
        t %= 3600 * 12;
        m = t % 3600;
        double ans = fabs(1.0 * t / 120 - 1.0 * m / 10);
        if (ans > 180) ans = 360 - ans;
        //printf("t = %d\n", t);
        //double ans = 1.0 * t / 120;
        printf("%.4lf\n", ans);
    }

    return 0;
}
