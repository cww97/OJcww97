#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
const int N = 233;
struct bigNum{
    int a[N];

    bigNum(){
        memset(a,sizeof(a),0);
        for (int i=0;i<N;i++)a[i] = 0;
    }

    void print(){
        for (int i = a[0]; i>0; i--){
            printf("%X",a[i]);
        }
        puts("");
    }

    bigNum operator + (const bigNum &b){
        bigNum c;
        c.a[0] = max(a[0], b.a[0]);
        int x = 0;
        for (int i=1;i<=c.a[0];i++){
            x += a[i] + b.a[i];
            c.a[i] = x % 16;
            x /= 16;
        }
        if (x) c.a[++c.a[0]] = x;
        return c;
    }

}a, b;
//ÄúÂè£¬javaÌâ

int qd(char x){
    if ('0' <= x && x <= '9')return x - '0';
    return x - 55;
}

bigNum jd(string st){
    bigNum ans;
    ans.a[0] = st.length();
    for (int i=1; i <= ans.a[0]; i++){
        ans.a[i] = qd(st[ans.a[0] - i]);
    }
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T;scanf("%d", &T);
    string st1, st2;
    for (int cas = 0;cas < T;cas++){
        printf("case #%d:\n", cas);
        cin >> st1 >> st2;
        a = jd(st1);
        b = jd(st2);
        bigNum c = a + b;
        c.print();
    }
    return 0;
}
