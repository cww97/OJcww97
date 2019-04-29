//一开始用矩阵快速幂，，，，MLE了，
//然后发现只摸7.。。找规律，，，循环节是48
#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,n;
    while(scanf("%d%d%d",&a,&b,&n)==3)
    {
        if(!a&&!b&&!n)
            break;
        int arr[48];
        arr[1]=1;
        arr[2]=1;
        for(int i=3;i<48;i++)
            arr[i]=((a*arr[i-1]+b*arr[i-2])%7);
        printf("%d\n",arr[n%48]);
    }
    return 0;
}

/*#include<cstdio>
#include<iostream>
using namespace std;
const int p=7;
struct matrix { int m[3][3]; };
matrix hk,kk;
int a,b,n;

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
  while (scanf("%d%d%d",&a,&b,&n)==3){
    if (a==0&&b==0&&n==0)break;
    hk.m[1][1]=a; hk.m[1][2]=1;
    hk.m[2][1]=b; hk.m[2][2]=0;
    kk=power(hk,n-1);
    //printf("%d %d\n%d %d\n",kk.m[1][1],kk.m[1][2],kk.m[2][1],kk.m[2][2]);
    printf("%d\n",kk.m[0][0]%p);
  }

  return 0;
}*/


