#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 9999;
const double EPS = 1e-6;
int n;
struct point{
    double x,y,z,dx,dy,dz;
    inline void read(){
        scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&z,&dx,&dy,&dz);
    }
}po[N];

struct Edge{
    double a,b,c;
    int from,to;
    bool operator < (const Edge &a)const{
        return c < a.c;
    }
}edges[N];
int E;
inline double sqr(double x){return x*x;}
inline void makeEdges(){
    E = 0;
    for (int i=1; i<n; i++){
        for (int j=i+1;j<=n;j++){
            edges[++E].a = sqr(po[i].dx - po[j].dx)
                         + sqr(po[i].dy - po[j].dy)
                         + sqr(po[i].dz - po[j].dz);
            edges[E].b = 2*( (po[i].dx - po[j].dx)*(po[i].x - po[j].x)
                            +(po[i].dy - po[j].dy)*(po[i].y - po[j].y)
                            +(po[i].dz - po[j].dz)*(po[i].z - po[j].z));
            edges[E].c = sqr(po[i].x - po[j].x)
                       + sqr(po[i].y - po[j].y)
                       + sqr(po[i].z - po[j].z);
            edges[E].from = i;
            edges[E].to = j;
        }
    }
    sort(edges + 1,edges + E + 1);
}

struct Event{
    double t;//time
    int newE, oldE;
    Event(double t=0,int n=0,int o=0):t(t),newE(n),oldE(o){}
    bool operator < (const Event &a) const {
        return t < a.t;
    }
};
vector <Event> events;
inline void makeEvents(){
    events.clear();
    for (int i=1; i<E; i++){
        for (int j=i+1;j<=E;j++){
            int s1 = i, s2 = j;
            if (edges[s1].a < edges[s2].a) swap(s1,s2);//*****
            double a = edges[s1].a - edges[s2].a;
            double b = edges[s1].b - edges[s2].b;
            double c = edges[s1].c - edges[s2].c;
            if (fabs(a) < EPS){//b*t + c = 0
                if (fabs(b) < EPS) continue;
                if (b>0){swap(s1,s2);b=-b;c=-c;}
                if (c>0) events.push_back(Event(-c/b,s1,s2));
            }else {
                double delta = b*b - 4*a*c;
                if (delta<EPS) continue;//no solution
                delta = sqrt(delta);
                double t1 = (-b-delta)/(2*a);
                double t2 = (-b+delta)/(2*a);
                if (t1>0)events.push_back(Event(t1,s1,s2));
                if (t2>0)events.push_back(Event(t2,s2,s1));
            }
        }
    }
    sort(events.begin(),events.end());
}

int f[N], pos[N], e[N];
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
inline int work(){
    for (int i=0;i<=n;i++)f[i]=i;
    memset(pos, 0, sizeof(pos));
    int cnt = 0;
    for (int i=1;i<=E;i++){//kruskal
        int x = F(edges[i].from);
        int y = F(edges[i].to  );
        if (x==y) continue;
        f[x] = y;
        e[pos[i]=++cnt] = i;
        if (cnt==n-1)break;
    }

    int ans = 1;
    for (int i=0;i<events.size();i++){
        if (!pos[events[i].oldE]) continue;
        if ( pos[events[i].newE]) continue;
        for (int i=0; i<=n; i++) f[i] = i ;
        int oldPos = pos[events[i].oldE];
        for (int j = 1;j<n;j++){
            if (j==oldPos)continue;
            int x = F(edges[e[j]].from);
            int y = F(edges[e[j]].to  );
            if (x != y) f[x] = y;
        }
        int x = F(edges[events[i].newE].from);
        int y = F(edges[events[i].newE].to  );
        if (x == y) continue;
        ans ++;
        pos[events[i].newE] = oldPos;
        e[oldPos] = events[i].newE;
        pos[events[i].oldE] = 0;
    }
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    for (int cas=0;~scanf("%d",&n);){
        for (int i=1;i<=n;i++)po[i].read();
        makeEdges() ;
        makeEvents();
        int ans = work();
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
