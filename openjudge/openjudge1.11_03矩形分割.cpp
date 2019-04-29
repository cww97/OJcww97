#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const LL N = 1e4 + 7;
const double EPS = 1e-7;

LL n;

struct Rect{
    // left, right, up, down, width, height
    LL l, r, u, w, h;

    void read(){
        scanf("%lld%lld%lld%lld", &l, &u, &w, &h);
        r = l + w;
    }

    // the area of this rectangle on the left of line x = mid
    LL areaL(LL mid){
        if (r <= mid) return w*h;
        if (mid <= l) return 0;
        return (mid-l) * h;
    }

    LL areaR(LL mid){
        if (r <= mid) return 0;
        if (mid <= l) return w*h;
        return (r-mid) * h;
    }
} rect[N];

bool check(LL mid){
    LL lsum = 0, rsum = 0;
    for (LL i = 0; i < n; i++){
        lsum += rect[i].areaL(mid);
        rsum += rect[i].areaR(mid);
    }
    //printf("mid = %d, %d: %d\n", mid, lsum, rsum);
    return lsum >= rsum;
}

bool checkB(LL mid, LL lsum){
    //printf("mid = %d\n", mid);
    LL sum =  0;
    for (LL i = 0; i < n; i++){
        sum += rect[i].areaL(mid);
    }
    return sum == lsum;
}

int main(){
    //freopen("in.txt", "r", stdin);
    LL R;
    scanf("%lld%lld", &R, &n);
    for (LL i = 0; i < n; i++){
        rect[i].read();
    }

    LL l = 0, r = R, mid;
    for (; l < r;){
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    LL lsum = 0;
    for (LL i = 0; i < n; i++) lsum += rect[i].areaL(l);

    r = R;
    for (; l < r;){
        mid = (l + r) / 2;
        if (checkB(mid, lsum)) l = mid + 1;
        else r = mid;
    }
    if (!checkB(l, lsum)) l--;
    printf("%lld\n", l);
    return 0;
}
