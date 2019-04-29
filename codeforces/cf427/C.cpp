#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e2 + 10;

int sky[13][M][M], sum[13][M][M];
int n, q, c;
struct star{
    int x, y, s;
    void read(){
        scanf("%d%d%d", &x, &y, &s);
        sky[0][x][y] += s;
    }
    void twinkle(int t){
        s++;
        if (s > c) s = 0;
        sky[t][x][y] += s;
    }
} stars[N];

int main(){
    //freopen("in.txt", "r", stdin);
    for (;~scanf("%d%d%d", &n, &q, &c);){
        memset(sky, 0, sizeof(sky));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++){
            stars[i].read();
        }
        for (int t = 1; t <= c; t++){
            for (int i = 0; i < n; i++){
                stars[i].twinkle(t);
            }
        }
        for (int t = 0; t <= c; t++){
            for (int i = 1; i <= 100; i++){
                for (int j = 1; j <= 100; j++){
                    sum[t][i][j] = sky[t][i][j] + sum[t][i][j-1] + sum[t][i-1][j] - sum[t][i-1][j-1];
                }
            }
        }

        for (int t, x1, y1, x2, y2; q--;){
            scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
            t = t % (c + 1);
            int ans = sum[t][x2][y2] - sum[t][x2][y1-1] - sum[t][x1-1][y2] + sum[t][x1-1][y1-1];
            printf("%d\n", ans);
        }
    }
    return 0;
}
