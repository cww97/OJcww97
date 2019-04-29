#include <bits/stdc++.h>
using namespace std;
const int N = 111;

char st[N];
int ans[N], A;

bool check(char* st){
    int train = 0;
    stack <int> S;
    for (int i = 0; i < strlen(st); i++){
        if (st[i] == 'A') ans[++A] = ++train;
        else if (st[i] == 'B') {
            if (S.size() == 5) return false;
            S.push(++train);
        }else{
            if (S.empty()) return false;
            ans[++A] = S.top();
            S.pop();
        }
    }
    return true;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%s", st);
    if (check(st)){
        puts("Yes");
        for (int i = 1; i <= A; i++){
            printf("%d\n", ans[i]);
        }
    }else{
        puts("No");
    }
	return 0;
}
