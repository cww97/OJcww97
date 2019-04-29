#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
const int N=10000;
int T,n,m;
int a[N];
int num[1000000];
int Map[256];
int scanc(){
    char ch=getchar();
    int x=0;
    for (;ch<'a'||ch>'z';ch=getchar());
    for (;ch>='a'&&ch<='z';ch=getchar()) x=x*10+Map[ch];
    return x;
}
int main(){
    scanf("%d",&T);
    for (int i='a';i<='c';i++) Map[i]=2;
    for (int i='d';i<='f';i++) Map[i]=3;
    for (int i='g';i<='i';i++) Map[i]=4;
    for (int i='j';i<='l';i++) Map[i]=5;
    for (int i='m';i<='o';i++) Map[i]=6;
    for (int i='p';i<='s';i++) Map[i]=7;
    for (int i='t';i<='v';i++) Map[i]=8;
    for (int i='w';i<='z';i++) Map[i]=9;
    for (;T--;){
        scanf("%d%d",&n,&m);
        memset(num,0,sizeof(num));
        for (int i=1;i<=n;i++) scanf("%d",&a[i]),num[a[i]]=1;
        for (int i=1;i<=m;i++){
            int x=scanc();
            if (num[x]>0) num[x]++;
        }
        for (int i=1;i<=n;i++) printf("%d\n",num[a[i]]-1);
    }
    return 0;
}
