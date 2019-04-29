#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 7;
char st[N];
int Hash[222], n;

int getMax(char ch){
    int ans = 0;
    for (char i = 'a'; i <= 'z'; i++){
        if (i == ch) ans = max(ans, Hash[i]-1);
        else ans = max(ans, Hash[i]);
    }
    return ans;
}

char FindChar(char last){
    n--;
    for (char i = 'a'; i <= 'z'; i++){
        if (!Hash[i]) continue;
        if (i == last) continue;
        int Max = getMax(i);
        if (Max * 2 > n + 1) continue;
        Hash[i]--;
        return i;
    }
    return '0';
}

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%s", st);
    int len = strlen(st);
    n = len;
    memset(Hash, 0, sizeof(Hash));
    for (int i = 0; i < len; i++) Hash[st[i]]++;
    int Max = getMax('0');
    if (Max * 2 > len + 1) puts("INVALID");
    else {
        char last = ' ';
        for (int i = 0; i < len; i++){
            last = FindChar(last);
            printf("%c", last);
        }
        puts("");
    }
    return 0;
}
