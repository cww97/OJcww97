#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e3 + 7;
const int INF = 0x3f3f3f3f;
int f[N];
struct job{
    int s, t, w;
    inline void read(){
        scanf("%d%d%d", &s, &t, &w);
    }
    bool operator < (const job &b) const {
        return t < b.t;
    }
} jobs[N];

int Search(int l, int r, const int &val){
    for (; l < r;){
        int mid = (l + r) >> 1;
        if (jobs[mid].t <= val) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main(){
    //freopen("in.txt", "r", stdin);
    for (int n, m, r; ~scanf("%d%d%d", &n, &m, &r);){
        jobs[0].t = -INF;
        for (int i = 1; i <= m; i++){
            jobs[i].read();
        }
        sort(jobs + 1, jobs + m+1);  // sort by end time

        f[0] = 0;  // dp
        for (int i = 1; i <= m; i++){
            //idx is the earliest overlap job
            int idx = Search(0, i, jobs[i].s - r);
            f[i] = max(f[i-1], f[idx-1] + jobs[i].w);
        }
        printf("%d\n", f[m]);
    }
    return 0;
}
