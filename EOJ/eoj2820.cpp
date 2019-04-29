#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 55;

int main(){
    //freopen("in.txt","r",stdin);
    string st;
    int a[N];
    for (;getline(cin,st);){
        int n = st.length();
        if (!n){puts("0");continue;}
        for (int i=0; i<n; i++){
            a[i] = (st[i]=='-')? 0: 1;
        }
        int cnt = 1, flag = a[0];
        int ans = cnt;
        for (int i=1; i<n;i++){
            if (flag ^ a[i]) {
                cnt++;
                flag ^= 1;
                ans = max(ans,cnt);
            }else {
                cnt = 1;
                flag = a[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
