#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int getVal(char ch){
    if (ch >= '0' && ch <= '9') return ch - '0';
    return ch - 'a' + 10;
}

int dist(int rgb, int col){
    rgb = rgb * 16 + rgb;
    return (rgb - col) * (rgb - col);
}

char getChar(int val){
    if (val < 10) return val + '0';
    return val + 'a' - 10;
}

int main(){
    char ch, ch1, ch2;
    scanf("%c", &ch);
    printf("%c", ch);
    for (int t = 0; t < 3; t++){
        scanf("%c%c", &ch1, &ch2);
        int num = getVal(ch1) * 16 + getVal(ch2);

        int Min = INF, ans = -1;
        for (int i = 0; i < 16; i++){
            if (dist(i, num) < Min){
                Min = dist(i, num);
                ans = i;
            }
        }
        printf("%c", getChar(ans));
    }
    puts("");
    return 0;
}
