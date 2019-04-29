#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    for (int x, y; cin >> x >> y;){
        int a = x * y - x - y;
        int b = (x - 1) * (y - 1) >> 1;
        printf("%d %d\n", a, b);
    }
    return 0;
}
