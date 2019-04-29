#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int P,W,H,a[1111],n;

bool check(int s){
    int lc=W/s;//line_character
    int pl=H/s;//page_line
    int line=0;
    for (int i=1;i<=n;i++){
        line+=a[i]/lc;
        if (a[i]%lc!=0)line++;
    }
    int page=line/pl;
    if (line%pl!=0)page++;
    return page <= P;
}

int main(){
    freopen("in.txt","r",stdin);
    int T;scanf("%d",&T);
    while (T--){
        scanf("%d%d%d%d",&n,&P,&W,&H);
        for (int i=1;i<=n;i++)scanf("%d",&a[i]);
        int L=1,R=min(W,H);
        while (L<R){
            int M=(L+R)>>1;
            if (check(M))L=M+1;
            else R=M-1;
        }
        if (!check(L))L--;
        printf("%d\n",L);
    }
    return 0;
}
