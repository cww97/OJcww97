#include<iostream>
using namespace std;
const int f[5][5]={{ 0,-1, 1, 1,-1},
                   { 1, 0,-1, 1,-1},
                   {-1, 1, 0,-1, 1},
                   {-1,-1, 1, 0, 1},
                   { 1, 1,-1,-1, 0}};
int i,n,na,nb,A=0,B=0;
int a[500],b[500];
int main(){
  cin>>n>>na>>nb;
  for (int i=1;i<=na;i++) cin>>a[i];
  for (int i=na+1;i<=n;i++) a[i]=a[i-na];
  for (int i=1;i<=nb;i++) cin>>b[i];
  for (int i=nb+1;i<=n;i++) b[i]=b[i-nb];
  for (int i=1;i<=n;i++){
    if (f[a[i]][b[i]]== 1) A++;
    if (f[a[i]][b[i]]==-1) B++;
  }
  cout<<A<<" "<<B<<endl;
  return 0;
}
