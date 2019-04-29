#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=233333;//20W

int Manacher(string st){
	int len=st.size();
	int *p=new int[len+1];
	memset(p,0,sizeof(p));
	int mx=0,id=0;
	for (int i=1;i<=len;i++){
		if (mx>i)p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while (st[i+p[i]]==st[i-p[i]])p[i]++;
		if (i+p[i]>mx){mx=i+p[i];id=i;}
	}
	int ma=0;
	for(int i=1;i<len;i++)ma=max(ma,p[i]);
	delete(p);
	return ma-1;
}

int main(){
	//freopen("fuck.in","r",stdin);
	char st[N];
	while (~scanf("%s",st)){
		string st0="$#";
		for (int i=0;st[i]!='\0';i++){
			st0+=st[i]; st0+="#";
		}
		printf("%d\n",Manacher(st0));
	}
	return 0;
} 
