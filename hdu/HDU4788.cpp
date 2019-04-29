#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string st,stt;
double k,kk;
int ti,T,n;

void fuck(){
	if (st[1]=='B')
	{printf("0.00%%\n");return;}
	kk=(1000/1024.0);
	k=kk*100;
	if (st[1]=='K') 
	{printf("%.2lf%%\n",(100-k));return;}
	k=k*kk;
	if (st[1]=='M') 
	{printf("%.2lf%%\n",(100-k));return;}
	k=k*kk;
	if (st[1]=='G') 
	{printf("%.2lf%%\n",(100-k));return;}
	k=k*kk;
	if (st[1]=='T') 
	{printf("%.2lf%%\n",(100-k));return;}
	k=k*kk;
	if (st[1]=='P') 
	{printf("%.2lf%%\n",(100-k));return;}
	k=k*kk;
	if (st[1]=='E') 
	{printf("%.2lf%%\n",(100-k));return;}
	k=k*kk;
	if (st[1]=='Z') 
	{printf("%.2lf%%\n",(100-k));return;}
	k=k*kk;
	if (st[1]=='Y') 
	{printf("%.2lf%%\n",(100-k));return;}
}

int main(){
	//freopen("fuck.in","r",stdin);
	scanf("%d",&T);
	for (ti=1;ti<=T;ti++){
		scanf("%d",&n);
		cin >> st;
		printf("Case #%d: ",ti);
		fuck();
	}
	return 0;
} 
