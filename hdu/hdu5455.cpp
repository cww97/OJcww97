#include<iostream>
#include<string>
#include<cstdio>
#include<string.h>

using namespace std;
int ti,t,i;
string st;

int main()
{
	freopen("fuck.in" ,"r",stdin);
	//freopen("fuck.out","w",stdout);
	scanf("%d",&t);
	for (int ti=1;ti<=t;ti++)
	{
		cin>>st;
		printf("Case #%d: ",ti);
		string stt="";
		int l=st.size();
		int haha=0;
		for (i=0;i<=l-1;i++) if (st[i]=='f')haha++;
		if (haha==l)
		{printf("%d\n",(l+1)/2);continue;}
		
		bool hhh=true;
		for (i=0;i<=l-1;i++)
		  if ((st[i]!='c')&&(st[i]!='f')){hhh=false;break;}
		if (!hhh){printf("%d\n",-1);continue;}
		  
		for (i=0;i<=l-1;i++)
			if (st[i]=='c') break;
		st.erase(0,i);
		for (int j=1;j<=i;j++) st=st+'f';
		//cout<<st<<endl;
		bool ok=true;
		for (i=0;i<=l-2;i++)
		  if ((st[i]=='c')&&(st[i+1]=='c'))ok=false;
		for (i=0;i<=l-3;i++)
		  if ((st[i]=='c')&&(st[i+1]=='f')&&(st[i+2]=='c'))ok=false;
		if (st[l-1]=='c')ok=false;
		if ((st[l-2]=='c')&&(st[l-1]=='f'))ok=false;
		if (!ok){printf("%d\n",-1);continue;}
		int ans=0;
		for (i=0;i<=l-1;i++)
		    if (st[i]=='c')ans++;
		printf("%d\n",ans);
	}
	return 0;
} 
