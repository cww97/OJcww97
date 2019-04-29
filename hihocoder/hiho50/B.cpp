#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200005];
struct node{
    int kong, pos;

    bool operator < (const node &b) const {
        if(kong != b.kong) return kong < b.kong;
        return pos > b.pos;
    }
};

int n,m,k;
priority_queue<int, vector<int>, greater<int> >q1;
priority_queue<node>q;

int main (){
    scanf("%d%d%d", &n, &m, &k);
    for(int x, i = 1; i <= m; i++){
        scanf("%d", &x);
        q1.push(x);
    }
    q1.push(0);
    q1.push(n+1);
    while(q1.size() != 1){
        int L = q1.top();
        q1.pop();
        int R = q1.top();
        node tmp;
        tmp.pos = (L + R) >> 1;
        tmp.kong = R-L-1;
        if(tmp.kong!=0)
            q.push(tmp);
    }

    int time = 0;
    while(time<k){
        time++;
        node tmp = q.top();
        q.pop();
        cout<<tmp.pos<<endl;
        node node1;
        node1.kong = (tmp.kong-1)/2;
        node1.pos = (tmp.pos-1) - node1.kong/2;
        if (node1.kong!=0) q.push(node1);

        node node2;
        node2.kong = tmp.kong - node1.kong-1;
        node2.pos = tmp.pos+(node2.kong+1)/2;
        if(node2.kong!=0)
            q.push(node2);
    }
    return 0;
}
