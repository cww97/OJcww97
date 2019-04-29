#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100;
int n, k, A;
int a[N];

char jd(int x){
    if (x<10)return x + '0';
    return x + 55;
}

int main(){
    int T;scanf("%d", &T);
    for (;T--;){
        bool fushu = 0;
        scanf("%d%d", &n, &k);
        if (n<0) {fushu = 1;n = -n;}
        for (int i = 0;n;i++){
            a[i] = n % k;
            n /= k;
            A = i;
        }

        if (fushu) putchar('-');
        for (int i=A;i>=0;i--){
            printf("%c", jd(a[i]));
        }
        puts("");
    }
    return 0;
}
