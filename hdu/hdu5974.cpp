#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b){return (!b)? a: gcd(b, a%b);}

int main()
{
    for (LL a, b; ~scanf("%lld%lld", &a, &b);){
        LL gc = gcd(a, b);
        a /= gc;
        b /= gc;
        LL delta = a*a - 4*b;
        if (delta < 0) puts("No Solution");
        else {
            LL i = (a + sqrt(delta)) / 2;
            LL j = a - i;
            if (i*j != b)puts("No Solution");
            else printf("%lld %lld\n", min(i,j)*gc, max(i,j)*gc);
        }
    }
    return 0;
}
