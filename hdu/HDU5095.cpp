#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int T;
int main(){
    scanf("%d",&T);
    for (;T--;){
        bool flag=0;
        int c;
        for (char x='p';x<='z';x++){
            if (x=='s'||x=='t') continue;
            scanf("%d",&c);
            if (c==0) continue;
            if (c>0&&flag){
                if (c==1) printf("+%c",x);
                else printf("+%d%c",c,x);
                flag=1;
            }else{
                if (c==1||c==-1){
                    if (c==1) printf("%c",x);
                    if (c==-1) printf("-%c",x);
                }
                else printf("%d%c",c,x);
                flag=1;
            }
        }
        scanf("%d",&c);
        if (c!=0){
            if (c>0&&flag){printf("+%d",c);}
			else{printf("%d",c);}
        }
        puts("");
    }
}
