#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n,m,i,j,tp,s[111];
char ch;
string a[111],st;

int sorted(int x){
	int kk=0;
	for (int i=0;i<n;i++)
	  for (int j=i+1;j<n;j++)
	    if (a[x][i]>a[x][j]) kk++;
	return kk;
}

int main (){
	scanf("%d%d%c",&n,&m,&ch);
	for (i=1;i<=m;i++){
		getline(cin,a[i]);
		s[i]=sorted(i);
	}
	for (i=1;i<=m;i++)
	  for (j=i+1;j<=m;j++)
	    if (s[i]>s[j]){
	    	st=a[i];a[i]=a[j];a[j]=st;
	    	tp=s[i];s[i]=s[j];s[j]=tp;
	    }
	for (i=1;i<=m;i++) cout<<a[i]<<endl;
	return 0;
}
