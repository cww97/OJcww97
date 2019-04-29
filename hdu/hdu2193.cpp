#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n,f[55];f[0]=1;f[1]=2;
    for (int i=2;i<50;i++)f[i]=f[i-1]+f[i-2]+1;
    while (scanf("%d",&n)==1&&n){
        int k=0;
        while (f[k]<=n)k++;
        printf("%d\n",--k);
    }
    return 0;
}
