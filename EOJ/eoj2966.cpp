#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;
int n;
char n2[100];

int main(){
    int T;scanf("%d", &T);
    for (int cas = 0;cas < T;cas++){
        scanf("%d", &n);
        itoa(n,n2,2);
        printf("case #%d:\n%s %X\n",cas,n2,n);
    }
    return 0;
}
