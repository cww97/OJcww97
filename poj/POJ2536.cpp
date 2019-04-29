#include <cstdio>
#include <vector>
#include <cstring>
//#define sqr(x) (x)*(x)
using namespace std;
const int N = 111;
template <class T>
T sqr(T x){
    return x*x;
}

struct Point{
    double x, y;
};
vector <Point> gophers, holes;
double dist(const Point &a, const Point &b){
    return sqr(a.x-b.x) + sqr(a.y-b.y);
}

struct Graph{
    vector <int> G[N];
    int boy_cnt, girl_cnt, girl[N];
    bool used[N];

    inline void init(const int &n, const int &m){
        boy_cnt = n;
        girl_cnt = m;
        for (int i = 0; i <= n; i++) G[i].clear();
    }

    inline void addEdge(int u, int v){
        //printf("addEdge: %d -> %d\n", u, v);
        G[u].push_back(v);
    }

    bool find_girl(int u){
        for (int i = 0; i < G[u].size(); i++){
            int &v = G[u][i];
            if (used[v]==false) { 
                used[v] = true;  
                if (girl[v] == 0 || find_girl(girl[v])) {   
                    girl[v] = u;  
                    return true;  
                }  
            }  
        }
        return false;
    }

    inline int hungary(){
        int all = 0;
        memset(girl, 0, sizeof girl);
        for (int i = 1; i <= boy_cnt; i++){
            memset(used, false, sizeof used);
            if (find_girl(i)) all++;
        }
        return all;
    }
} g;



int main(){
    freopen("in.txt", "r", stdin);
    for (int n, m, s, v; scanf("%d%d%d%d", &n, &m, &s, &v) == 4;){
        double tmp_x, tmp_y;
        gophers.clear();
        for (int i = 0; i < n; i++){
            scanf("%lf%lf", &tmp_x, &tmp_y);
            gophers.push_back(Point{tmp_x, tmp_y});
        }

        holes.clear();
        for (int i = 0; i < m; i++){
            scanf("%lf%lf", &tmp_x, &tmp_y);
            holes.push_back(Point{tmp_x, tmp_y});
        }

        g.init(n, m);
        int limited = sqr(s*v);
        for (int i = 0; i < gophers.size(); i++){
            for (int j = 0; j < holes.size(); j++){
                if (dist(gophers[i], holes[j]) <= limited){
                    g.addEdge(i+1, j+1);
                }
            }
        }
        int ans = n - g.hungary();
        printf("%d\n", ans);
    }
    return 0;
}