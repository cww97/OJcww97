#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
map<char, int> mp;

int main(){
    mp['v'] = 0;
    mp['<'] = 1;
    mp['^'] = 2;
    mp['>'] = 3;
    //freopen("in.txt", "r", stdin);
    char chA, chB;
    int n;
    for (;cin >> chA >> chB >> n;){
        int a = mp[chA];
        int b = mp[chB];
        n %= 4;
        bool ok1 = 0, ok2 = 0;
        if ((a + n) % 4 == b) ok1 = true;
        if ((a - n + 4) % 4 == b) ok2 = true;
        if (ok1 && ok2) puts("undefined");
        else if (ok1) puts("cw");
        else puts("ccw");
    }
    return 0;
}
