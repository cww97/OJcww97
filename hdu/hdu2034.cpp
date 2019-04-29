#include<set>
#include<cstdio> 
#include<iostream>
using namespace std;
int main(){
	//freopen("fuck.in","r",stdin);
	int n,m,x;
	while (scanf("%d%d",&n,&m)==2){
		if (!n&&!m)break;
		set<int>s1;
		for (int i=0;i<n;i++){
			scanf("%d",&x);
			s1.insert(x);
		}
		for (int i=0;i<m;i++){
			scanf("%d",&x);
			if (s1.find(x)!=s1.end())s1.erase(x);
		}
		if (s1.begin()==s1.end())puts("NULL");
		else {
			for (set<int>::iterator it=s1.begin();it!=s1.end();it++){
				printf("%d ",*it);
			}
			puts("");
		}
	}
	return 0;
}
