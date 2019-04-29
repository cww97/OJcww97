#include <cstdio>
#include <iostream>
using namespace std;
const double EPS = 1e-12;

double f(double x){
    return x*x*x*x*x - 15*x*x*x*x + 85*x*x*x - 225*x*x + 274*x - 121;
}

int main(){
    double l = 1.5, r = 2.4;
    for (; l + EPS < r;){
        double mid = (l+r) / 2.0;
        if (f(mid) > 0) l = mid;
        else r = mid;
    }
    printf("%.6f\n", l);
    return 0;
}
