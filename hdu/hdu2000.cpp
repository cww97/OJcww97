#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int i,j;
string st;
char ch;

int main(){
  while (cin>>st){
    for (i=0;i<3;i++)
      for (j=i+1;j<3;j++){
        if (st[i]>st[j])
          {ch=st[i]; st[i]=st[j]; st[j]=ch;}
    }
    printf("%c %c %c\n",st[0],st[1],st[2]);
  }
  return 0;
}
