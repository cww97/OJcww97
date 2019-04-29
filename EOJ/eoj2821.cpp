#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
const int N = 55;

struct polynomial{
    int a[N];

    int operator [] (const int &x){
        return this->a[x];
    }

    void init(){
        for (int i=0; i<N; i++) a[i] = 0;
    }

    polynomial operator * (const polynomial &y){
        polynomial ret;
        ret.init();
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                ret.a[i + j] += a[i] * y.a[j];
            }
        }
        return ret;
    }

    void print(){
        int ans[N], A = 0;
        for (int i=N-1; i>=0; i--) if (a[i]){
            ans[++A] = a[i];
        }
        for (int i=1; i<A; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[A]);
    }
};

stringstream stream;
int str2num(string s){
    if (s == "+")return  1;
    if (s == "-")return -1;
    int ret = 1;
    stream.clear();
    stream << s;
    stream >> ret;
    return ret;
}

polynomial getP(string st){
    polynomial ans;
    ans.init();
    int n = 0;
    if (st[0] != '-') st = "+" + st;
    for (; st != ""; ){
        int pos = st.find("x");
        if (pos == -1){
            ans.a[0] = str2num(st);
            break;
        }
        string tmp = st.substr(0, pos);
        int jd = str2num(tmp);
        st.erase(0,pos+1);
        if (st[0] == '^'){
            st.erase(0,1);
            pos = min(st.find("+"), st.find("-"));
            ans.a[str2num(st.substr(0,pos))] = jd;
            st.erase(0,pos);
        }else{
            ans.a[1] = jd;
        }
    }
    //ans.print();
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    string st1, st2;
    for (;cin>>st1>>st2;){
        polynomial a = getP(st1);
        polynomial b = getP(st2);
        polynomial c = a * b;
        c.print();
    }
    return 0;
}
