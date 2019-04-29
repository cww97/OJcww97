#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,x,a[11]; 
int main(){
    //freopen("fuck.in","r",stdin);
    for(;~scanf("%d",&n);){
        int mi=999999;
        for(int i=1;i<=9;i++){
            scanf("%d",&a[i]);
            mi=min(a[i],mi);
        }
        int ma=(n/mi),left=n-(ma*mi);
        if(!ma)puts("-1");
        else{
          while(ma--)
            for(int i=9;i>=1;i--)
              if(left>=a[i]-mi){
                left-=a[i]-mi;
                printf("%d",i);
                break;
              }
		}
        puts("");
    }
    return 0;
}
