#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200400;
string ans;
int _start,_end;

int Manacher(string st){
	int len=st.size();
	int *p=new int[len+1];
	memset(p,0,sizeof(p));
	int mx=0,id=0;
	for (int i=1;i<=len;i++){
		if (mx>i)p[i]=min(p[id*2-i],mx-i);
		else p[i]=1;
		while (st[i+p[i]]==st[i-p[i]])p[i]++;
		if (i+p[i]>mx)mx=i+p[i],id=i;
	}
	int ma=0,ii;
	for (int i=1;i<len;i++)
		if (p[i]>ma)ma=p[i],ii=i;
	ma--;
	_start=((ii-ma+1)>>1)-1;
	_end  =((ii+ma-1)>>1)-1;
	ans="";
	for (int i=ii-ma;i<=ii+ma;i++)
		if (st[i]!='#')ans+=st[i];
	delete(p);
	return ma;
}

void writeln(char ch,string st){
	char tag='a'-1;
	map<char,char>t;
	for (char i=ch;i<='z';i++)t[i]=++tag;
	for (char i='a';i< ch;i++)t[i]=++tag;
	int len=st.size();
	printf("%d %d\n",_start,_end);
	for (int i=0;i<len;i++)printf("%c",t[st[i]]);
	puts("");
}

int main(){
	char ch,st[N];
	while (~scanf("%c %s\n",&ch,st)){
		string st0="$#";
		for (int i=0;st[i]!='\0';i++)
			{st0+=st[i];st0+="#";}
		if (Manacher(st0)==1)puts("No solution!");
		else writeln(ch,ans);
	}
	return 0;
} 
