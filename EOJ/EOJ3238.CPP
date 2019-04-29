#include <bits/stdc++.h>
using namespace std;
const int N = 111;

bool vis[333]; // visited

struct node{
    string st;
    int cnt; // count

    inline void read(){
        cin >> st;
        cnt = 0;
        //memset(vis, 0, sizeof vis);
        for (int i = 0; i < 333; i++) vis[i] = 0;
        for (int i = 0; i < st.length(); i++){
            if (vis[st[i]] == 1) continue;
            vis[st[i]] = 1;
            cnt++;
        }
    }

    bool operator < (const node &b) const{
        if (cnt == b.cnt) return st < b.st;
        return cnt > b.cnt;
    }
} arr[N];


int main(){
    //freopen("in.txt", "r", stdin);
    int __;
    scanf("%d", &__);
    for (int n, _ = 0; _ < __; _++){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            arr[i].read();
        }
        sort(arr, arr + n);
        printf("case #%d:\n", _);
        for (int i = 0; i < n; i++){
            cout << arr[i].st << endl;
        }
    }
    return 0;
}
