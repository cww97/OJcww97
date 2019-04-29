#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int ff[60],n;
const int p=10000;
struct matrix { int m[3][3]; };
matrix hk,kk;

matrix mc(matrix x,matrix y){
  matrix xy;
  xy.m[1][1]=(x.m[1][1]*y.m[1][1]+x.m[1][2]*y.m[2][1]) % p;
  xy.m[1][2]=(x.m[1][1]*y.m[1][2]+x.m[1][2]*y.m[2][2]) % p;
  xy.m[2][1]=(x.m[2][1]*y.m[1][1]+x.m[2][2]*y.m[2][1]) % p;
  xy.m[2][2]=(x.m[2][1]*y.m[1][2]+x.m[2][2]*y.m[2][2]) % p;
  return xy;
}

matrix power(matrix x,int t){
    if(t==1) return hk;
    matrix tt=power(x,t>>1);
    tt=mc(tt,tt);
    if (t&1) tt=mc(tt,x);
    return tt;
}

int main(){
    hk.m[1][1]=1; hk.m[1][2]=1;
    hk.m[2][1]=1; hk.m[2][2]=0;
    ff[0]=0;ff[1]=1;
    for (int i=2;i<=40;i++) ff[i]=(ff[i-1]+ff[i-2]);
    
    while (scanf("%d",&n)==1){
        if (n<=39) printf("%d\n",ff[n]);
        else {
            double p=log10(1/sqrt(5))+n*log10((1+sqrt(5))/2);//前4位 
            p = p - floor(p);
            int ans = (int)(pow(10,p)*1000);
            kk=power(hk,n);                                 //后四位 
            printf("%d...%04d\n",ans,kk.m[2][1]);
        }
    }
    return 0;
}

