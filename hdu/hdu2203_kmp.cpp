//hdu 2203 cww97
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=100007;
char st1[N],st2[N];
int Next[N];

void GetNext(char *a){
    int i=0,j=-1,len=strlen(a);
    Next[0]=-1;
    while (i<len){
        if (j==-1||a[i]==a[j]){
            if (a[++i]!=a[++j])Next[i]=j;
            else Next[i]=Next[j];
            //printf("%c:  %d\n",a[i],next[i]);
        }else j=Next[j];
    }
}

bool kmp(char *a,char *b){
    int A=strlen(a),B=strlen(b),i=0,j=0;
    GetNext(b);
    while (i<A&&j<B){
        if (j==-1||a[i]==b[j])i=(i+1)%A,j++;
        else j=Next[j];
        if (!i&&!j)break;
    }
    return j==B;
}

int main(){
    //freopen("fuck.in","r",stdin);
    while (cin>>st1>>st2){
        int l1=strlen(st1),l2=strlen(st2);
        if (l1<l2)puts("no");
        else{
            if (kmp(st1,st2))puts("yes");
            else puts("no");
        }
    }
    return 0;
}
