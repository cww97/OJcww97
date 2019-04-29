#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 111;

char st[N];
map<char, double> mp;

bool cmp(char a, char b){
    bool upA = 0, upB = 0;
    if (a < 'a') {a += 'a' - 'A'; upA = 1;}
    if (b < 'a') {b += 'a' - 'A'; upB = 1;}

    if (mp[a] != mp[b]) return mp[a] > mp[b]; // f

    if (a == b){
        if (upA == upB) return 1;
        if (upA) return 0;
        return 1;
    }
    return a < b;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int __;
    scanf("%d", &__);
    for (int n, _ = 0; _ < __; _++){
        printf("case #%d:\n", _);
        mp.clear();
        double tmp;
        for (char i = 'a'; i <= 'z'; i++){
            scanf("%lf", &tmp);
            mp[i] = tmp;
        }
        scanf("%s", st);
        sort(st, st + strlen(st), cmp);
        printf("%s\n", st);
    }
    return 0;
}
