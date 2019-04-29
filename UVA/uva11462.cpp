#include <cstdio>
#include <cstring>
using namespace std;
const int N = 111;
int n, cnt[N];

int main(){
    for (; scanf("%d", &n) == 1 && n;){
        memset(cnt, 0, sizeof cnt);
        for (int x;n--;){
            scanf("%d", &x);
            cnt[x]++;
        }

        bool first = true;
        for (int i = 1; i <= 100; i++){
            for (int j = 0; j < cnt[i]; j++){
                if (!first) printf(" ");
                first = false;
                printf("%d", i);
            }
        }
        puts("");
    }
    return 0;
}
