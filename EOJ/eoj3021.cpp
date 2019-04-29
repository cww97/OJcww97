#include <bits/stdc++.h>
using namespace std;
const int N = 222;
char st[N]; // 原字符串
char arr[N]; // 存所有的字母，排序用
int n, A;

int main(){
    //freopen("in.txt", "r", stdin);
    int _;
    scanf("%d\n", &_);
    for (int cas = 0; cas < _; cas++){
        printf("case #%d:\n", cas);
        n = 0;  // 多组数据，将st和n清零
        memset(st, 0, sizeof st);

        for (char ch = '0'; ch != '\n';){ // 读一行
            scanf("%c", &ch);
            st[n++] = ch;
        }

        A = 0; // 得到所有字母
        for (int i = 0; i < strlen(st); i++){
            if (st[i] >= 'A' && st[i] <= 'Z'){
                arr[A++] = st[i];
            }
        }
        sort(arr, arr + A);  // 排序

        int now = 0;
        for (int i = 0; i < strlen(st); i++){
            if (st[i] >= 'A' && st[i] <= 'Z'){
                printf("%c", arr[now++]);
            }else{
                printf("%c", st[i]);
            }
        }
    }
    return 0;
}
