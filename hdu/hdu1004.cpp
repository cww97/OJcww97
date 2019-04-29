#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string st£¬co[10000];
int ba[10000],B;

int lo(string x){
  for(int i=1;i<=B;i++)
    if (co[i]==x)return i;
  return -1;
}

int main(){
  int n;
  while (scanf("%d",&n)){
    if (n==0)break;
    memset(ba,0,sizeof(ba));
    B=0;
    for (int i=1;i<=n;i++){
        cin>>st;
        int k=lo(st);
        if (k==-1)
          {ba[++B]++;co[B]=st;}
        else ba[k]++;
    }
    int ma=0;
    for (int i=1;i<=B;i++){
      if (ba[i]>ma){
        ma=ba[i];
        st=co[i];
      }
    }
    cout<<st<<endl;
  }
  return 0;
}
