#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100;

int main(){
    //freopen("in.txt","r",stdin);
    char st[23];
    for (;scanf("%s",st) == 1;){
        if (strstr(st,".") == NULL) {
            int n = atoi(st);
            sprintf(st,"%08x",n);
        }else{
            double n = atof(st);
            sprintf(st,"%016I64x", n);
        }

        int len = strlen(st);
        for (int i=len/2;i>0;i--){
            printf("%c%c ",st[i*2-2],st[i*2-1]);
        }
        puts("");
    }
    return 0;
}
